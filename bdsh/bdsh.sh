#!/bin/sh

#parsing : Aucun arguments
if [ $# -eq 0 ]; then
    echo -e "Syntax error : Usage <command> <params...>"
    exit
fi

if [ $# -gt 7 ]; then
    echo -e "Syntax error : Usage 5 parameters max (Options included)"
    exit
fi

#parsing expression without --
if [ "$1" != "--" ]; then
    for i in {1..5}
    do
        if [ "$1" ] && [ "$1" != "-f" ] && [ "$1" != "-k" ]; then

            if [ -z "$command" ]; then
                command=$1
                shift

            elif [ "$command" ] && [ -z "$val2" ]; then
                val2=$1
                shift

            elif [ "$val2" ] && [ -z "$val3" ]; then
                val3=$1
                shift

            elif [ "$val3" ] && [ -z "$val4" ]; then
                val4=$1
                shift
            fi
        fi
        if [ "$1" = "-f" ]; then
            f="1"
            shift
            db=$1
            shift

        elif [ "$1" = "-k" ]; then
            k="1"
            shift
        fi
    done
fi

#parsing expression with --
if [ "$1" = "--" ]; then
    shift
    for i in {1..5}
    do

        if [ "$1" ]; then

            if [ -z "$command" ]; then
                command=$1
                shift

            elif [ "$command" ] && [ -z "$val2" ]; then
                val2=$1
                shift

            elif [ "$val2" ] && [ -z "$val3" ]; then
                val3=$1
                shift
            elif [ "$val3" ] && [ -z "$val4" ]; then
                val4=$1
                shift

            fi

        fi

    done
fi

# if [ "$command" = "put" ] || [ "$command" = "select" ]; then
#     if [ "$" = `echo ${val2:0:1}` ]  && [ "$" = `echo ${val3:0:1}` ]; then
#         if [ "$val2" = "$val3" ]; then
#             echo "Syntax error : Usage <select> <key-param-req> <value-param-req or key-param-req>"
#           error="1"
#             exit
#         fi
#     fi
# fi

# if [ "$command" = "select" ]; then
#     if [ $val3 ]
#         echo "Syntax error : Usage <select> <key-param-req> <value-param-req or key-param-req>"
#         error="1"
#         exit
#     fi
# fi


if [ "$command" = "put" ]; then
    if [ -z "$val2" ] || [ -z "$val3" ] || [ "$val4" ]; then
        echo "Syntax error : Usage <put> <key-param-req> <value-param-req or key-param-req>"
        error="1"
        exit
    fi
fi


#inialisation db par defaut
if [ -z $db ]; then
    db="db.sh"
fi

#parcours dossier
if [ -w "$db" ]; then
    tmpls="1"
fi

#fichier existe ?
if [ -z "$tmpls" ]; then
    echo "No base found : file $db"
    exit
fi

#option -f existe ?
if [ -z "$f" ]; then
    f="0"
fi

#option -k existe ?
if [ -z "$k" ]; then
    k="0"
fi

# echo "$command"
# echo "$val2"
# echo "$val3"
# echo "============"
# echo "$f"
# echo "$db"
# echo "============"
# echo "$k"
# echo "============"

# command flush
if [ "$command" = "flush" ]; then
    echo -n "" > $db
    exit
fi

key2="0"
# convert val2 -$
if [ "$val2" ]; then
    if [ "$" = `echo ${val2:0:1}` ]; then
        key2="1"
        val2=`echo "$val2" | sed "s/^.//g"`
    fi
fi

key3="0"
# convert val3 -$
if [ "$val3" ]; then
    if [ "$" = `echo ${val3:0:1}` ]; then
        key3="1"
        val3=`echo "$val3" | sed "s/^.//g"`
    fi
fi

# command select
if [ "$command" = "select" ] && [ -z "$val3" ]; then
    if [ -z "$val2" ]; then
        if [ "$k" = "1" ]; then
            cat $db | grep -v "^ *$"
        else
            for line in $(cat $db); do
                len=`echo ${#val2}`
#                    echo $len
                comp=`echo $line | sed "s/^.*=//1"`
                comp2=`echo ${#comp}`
#                    echo $comp2
# #
                if [ $len -gt $comp2 ]; then
                    echo ${line: `echo ${#val2} + 1`}
                else

                    echo "$line" | sed "s/^.*=//1"
                fi
#                echo ${line: `echo ${#val2} + 1`}
            done
        fi
    else
        for line in $(cat $db | grep -- "$val2"); do
            if [ "$key2" = "1" ]; then
                if [ "$k" = "1" ]; then
                    echo $line
                else
                    len=`echo ${#val2}`
#                    echo $len
                    comp=`echo $line | sed "s/^.*=//1"`
                    comp2=`echo ${#comp}`
#                    echo $comp2
# #
		    test=`echo ${#line}`
		    echo "$test"
                    if [ $len -gt $comp2 ]; then
                        echo  ${line: `echo ${#val2} + 1`: $test}
                    else
                        echo "$line" | sed "s/^.*=//1"
                    fi
                fi
            else
                if [ "$k" = "1" ]; then
                    echo $line
                else
                    len=`echo ${#val2}`
#                   echo $len
                    comp=`echo $line | sed "s/^.*=//1"`
                    comp2=`echo ${#comp}`

#                   echo $line | sed "s/^.*=//1"
#                    echo ${line: `echo ${#val2} + 1`}  | sed "s/^.*=//1"
                    if [ $len -gt $comp2 ]; then
                        echo ${line: `echo ${#val2} + 1`}
                    else
                        echo "$line" | sed "s/^.*=//1"
                    fi

                fi
            fi
        done
    fi
    exit
elif [ "$command" = "select" ] && [ "$val3" ]; then
    echo "Syntax error : Usage <select> <key-param-req> <value-param-opt>"
fi



# command del
if [ "$command" = "del" ]; then
    # if [ -z $val2 ] || [ "$key2" != "1" ]; then
    #     echo "Syntax error : Usage <del> <key-param-req> <value-param-opt>"
    #     exit
    # fi

    if [ "$val4" ]; then
        echo "Syntax error : Usage <select> <key-param-req> <value-param-opt>"
        exit
    fi
    if [ "$val2" ] && [ -z "$val3" ]; then
        for line in $(cat $db | grep -- "$val2"); do
            tmp=`echo $line | grep "^$val2=" | sed "s/=.*$/=/g"`
            valtmp=`echo $line | grep "^$val2=" | sed "s/^.*=//g"`
            sed -i "/$tmp*/d" "$db"
            if [ "$valtmp" ]; then
                wr="1"
            fi
        done
        if [ "$wr" = "1" ]; then
            echo "$tmp" >> $db
        fi
    elif [ "$val2" ] && [ "$val3" ] && [ "$key3" != "1" ]; then
        for line in $(cat $db | grep -- "$val2"); do
            valtmp=`echo $line | grep "^$val2=" | sed "s/^.*=//g"`
            tmp=`echo $line | grep "^$val2=" | sed "s/=.*$/=/g"`
            if [ "$valtmp" = "$val3" ]; then
                sed -i "/$tmp$valtmp/d" "$db"
            fi
        done
    else
        echo "Syntax error : Usage <del> <key-param-req> <value-param-opt>"
        exit
    fi
fi

# valtmp="null"
# tmp="null"

# command put
if [ "$command" = "put" ] && [ "$error" != "1" ]; then
    if [ -z "$val2" ] || [ -z "$val3" ] || [ "$val4" ]; then
        # echo "Syntax error : Usage <put> <key-param-req> <value-param-req or key-param-req>"
        exit
    fi
    if [ "$val2" ] && [ "$key3" != "1" ]; then
        for line in $(cat $db | grep -- "$val2"); do
            valtmp=`echo $line | grep "^$val2=" | sed "s/^.*=//g"`
            tmp=`echo $line | grep "^$val2=" | sed "s/=.*$/=/g"`
          #  echo "$valtmp"
          #  echo "$tmp"
        done
        if [ "$val3" ] && [ -z "$tmp" ]; then
            echo "$val2=$val3" >> $db
        elif [ "$val3" ] && [ -z "$valtmp" ] || [ "$valtmp" != "$val3" ]; then
            sed -i "/$tmp$valtmp/d" "$db"
            echo "$val2=$val3" >> $db
        elif [ -z  "$val3" ] && [ -z "$tmp" ]; then
            echo "$val2=$val3" >> $db
        fi
    elif [ "$val2" ] && [ "$key3" = "1" ]; then
        for line in $(cat $db | grep -- "$val3"); do
            if [ `echo $line | grep "^$val3=" | sed "s/^.*=//g"` ]; then
                valtmp=`echo $line | grep "^$val3=" | sed "s/^.*=//g"`
            fi
        done
        for line in $(cat $db | grep -- "$val2"); do
           # if [`echo $line | grep "^$val2=" | sed "s/=.*$/=/g"` ]; then
            tmp=`echo $line | grep "^$val2=" | sed "s/=.*$/=/g"`
                   # fi
        done
        # valeur dans clef 3
        # adresse clef 2
        # si val3 est non-null et que la clef fichier est null
        if [ "$valtmp" ] && [ -z "$tmp" ]; then
            echo "$val2=$valtmp" >> $db
        fi
        # si val3 est non-null et que la clef fichier existe
        # boucle pour verifier valeur a l adresse val2
        for line in $(cat $db | grep -- "$val2"); do
            if [ `echo $line | grep "^$val2=" | sed "s/^.*=//g"` ]; then
                valtmp2=`echo $line | grep "^$val2=" | sed "s/^.*=//g"`
            fi
        done
        # echo "$tmp"
        # echo "$valtmp"
        # echo "$valtmp2"
        if [ -z "$valtmp2" ]; then
            echo "$val2=$valtmp" >> $db
        fi
        if [ "$tmp" ] && [ "$valtmp" != "$valtmp2" ]; then
            sed -i "/$tmp$valtmp2/d" "$db"
            echo "$val2=$valtmp" >> $db
        fi

    fi
    exit
fi
