;; BOCAL STAFF 2010-2011
;; FEDORA DUMP
(add-to-list 'load-path "~/.emacs.d/auto/")
(add-to-list 'load-path
             "~/.emacs.d/plugins")
(require 'yasnippet-bundle)

;;On supprime ce qui est inutile (Barre d'outils, scroll)
(menu-bar-mode -1)

;;AUTO COMPLETE

(require 'auto-complete-config)
(add-to-list 'ac-dictionary-directories "/home/cottin_j/.emacs.d/auto/ac-dict")
(ac-config-default)
;; END AUTO COMPLETE

;;Ici on parle UTF-8
(set-language-environment "UTF-8")

;;TUAREG MODE
(add-to-list 'load-path "~/.elisp/tuareg-mode")
(autoload 'tuareg-mode "tuareg" "Major mode for editing Caml code" t)
(autoload 'camldebug "camldebug" "Run the Caml debugger" t)
(autoload 'tuareg-imenu-set-imenu "tuareg-imenu"
  "Configuration of imenu for tuareg" t)
(add-hook 'tuareg-mode-hook 'tuareg-imenu-set-imenu)
(setq auto-mode-alist
      (append '(("\\.ml[ily]?$" . tuareg-mode)
                ("\\.topml$" . tuareg-mode))
              auto-mode-alist))
;; END TUAREG


;; Reduit la fontion sur elle meme
(add-hook 'c-mode-common-hook 'hs-minor-mode)
(add-hook 'lisp-mode-hook 'hs-minor-mode)
(add-hook 'emacs-lisp-mode-hook 'hs-minor-mode)
(add-hook 'python-mode-hook 'hs-minor-mode)
(global-set-key [f8] 'hs-hide-block)

;; Et la 'de'reduit
(global-set-key [f9] 'hs-show-block)

;; Commente la zone
(global-set-key [f4] 'comment-region)

;; decommente la zone
(global-set-key [f5] 'uncomment-region)

;; Ctrl-c r pour afficher le rechercher/remplacer
(global-set-key "\C-cr" 'replace-string)

;;fenetre de compil little
(setq compilation-window-height 25)
;; Bold line
(global-hl-line-mode t)
(custom-set-faces
 '(highlight ((t (:weight bold)))))

;;f1 = manuel gnome
;;f2 = autoindent

(global-set-key [f7] 'std-file-header)
(global-set-key [f12] 'global-linum-mode)

;;affiche les espaces inutile
(setq-default show-trailing-whitespace t)

;; Pour ne pas avoir à taper en entier la réponse yes/no
(fset 'yes-or-no-p 'y-or-n-p)

;;Autopair;;;;;;;;;;;;;;;;;
(require 'autopair)
(autopair-global-mode) ;; to enable in all buffers

;; auto-indent on F2;;;;;;;;;;;;;;;;;;;;;
(require 'indent-file)
(add-hook 'emacs-lisp-mode-hook 'indent-file-when-save)
(add-hook 'emacs-lisp-mode-hook 'indent-file-when-visit)
(global-set-key [f2] 'indent-whole-buffer)

;; Affiche le numéro de ligne et de colonne;;;;;;;;;;;;;;;;;;
(column-number-mode t)
(line-number-mode t)

;; Afficher la 'parenthèse correspondante';;;;;;;;;;;;;;;;
(require 'paren)
(show-paren-mode)

;; Header;;;;;;;;;;;;;;;;;;;;;;;;;;
(load "std.el")
(load "std_comment.el")

;; Les skeleton;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(load-file "~/.emacs.d/skeleton.el")


;; Si Makefile vide, creer une makefile;;;;;;;;;;;;;;;;;;;;;
(add-hook 'find-file-hook
          (lambda()
            (if (and
                 (string-match "\\Makefile$" (buffer-file-name))
                 (= (buffer-size) 0))
                (create-makefile))))

;; Si header vide, creer un header protege;;;;;;;;;;;;;;;;;;;;;;;;
(add-hook 'find-file-hook
          (lambda()
            (if (and
                 (string-match "\\.h$" (buffer-file-name))
                 (= (buffer-size) 0))
                (insert-protect-header
                 (goto-line 13)))))

