#include	"Player.hpp"
#include	"States.hh"
#include	"Edges.hh"

Player::Player(int ID, Socket &comm, Request &request, ParserZappyClient &parser)
  :Entity(ID)
  ,comm(comm)
  ,lastRequest(request)
  ,parser(parser)
{
  this->sM = new StateMachine<Player>(*this, FSM_QUIT);
  State<Player> *immobile = new StateImmobile();
  State<Player> *team = new StateChooseCamp();
  State<Player> *world = new StateLearnWorldSize();
  State<Player> *avance = new StateAvance();
  State<Player> *broadcast = new StateBroadcast();
  State<Player> *droite = new StateDroite();
  State<Player> *gauche = new StateGauche();
  State<Player> *drop = new StateDrop();
  State<Player> *fork = new StateFork();
  State<Player> *incante = new StateIncante();
  State<Player> *look = new StateLook();
  State<Player> *take = new StateTake();
  State<Player> *inventory = new StateInventory();

  /*
  ** composite : can be Or/And relation.
  ** accepts other composite edges.
  ** Or edge example :
  **
  ** Edge<Player>  *test = new CompositeEdge<Player>();
  ** test->isOrEdge(); / test->isAndEdge();
  ** test->addEdge(numeric);
  ** test->addEdge(someOtherEdge)
  */

  Edge<Player>	*always = new ForeverEdge();
  Edge<Player>	*hello = new BienvenueEdge();
  Edge<Player>  *ko = new KOEdge();
  Edge<Player>  *ok = new OKEdge();
  Edge<Player>  *numeric = new NumericEdge();

  this->sM->addState(team);
  this->sM->addState(world);
  this->sM->addState(immobile);
  this->sM->addState(avance);
  this->sM->addState(broadcast);
  this->sM->addState(droite);
  this->sM->addState(gauche);
  this->sM->addState(drop);
  this->sM->addState(fork);
  this->sM->addState(incante);
  this->sM->addState(look);
  this->sM->addState(take);
  this->sM->addState(inventory);
  this->sM->setInitialState(immobile);

  this->sM->addLink("immobile", hello, "team choice");
  this->sM->addLink("immobile", always, "immobile");
  this->sM->addLink("team choice", numeric, "world size");
  this->sM->addLink("world size", numeric, "avance");
  this->sM->addLink("avance", ok, "inventaire");
  this->sM->addLink("inventaire", always, "voir");
  this->sM->addLink("voir", always, "avance");
  this->sM->addLink("avance", ko, "immobile");
}

Player::~Player()
{
}

StateMachine<Player>	&Player::getIA()
{
  return (*this->sM);
}

bool	Player::update()
{
  if (!this->sM->next())
    return (false);
  this->lastRequest.setType(REQ_NONE);
  this->lastRequest.flushNumericList();
  if (!parser.readRequest(this->lastRequest))
    std::cerr << "request error" << std::endl;
  std::cout << "request : " << this->lastRequest.getType() << std::endl;
  this->sM->getState()->execute(this);
  return (true);
}

int	Player::request(std::string &req)
{
  req +=  "\n";
  return (this->comm.sendData<char>(req.c_str(), req.length()));
}

Request const	&Player::getLastRequest() const
{
  return (this->lastRequest);
}

void          Player::setLastRequest(Request &req)
{
  this->lastRequest = req;
}
