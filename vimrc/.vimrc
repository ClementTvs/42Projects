:set number
:set smartindent
:set autoindent
:set termguicolors

call plug#begin('~/.vim/plugged')

Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'preservim/nerdtree'
Plug 'neoclide/coc-highlight'
Plug 'tpope/vim-fugitive'
Plug 'vim-airline/vim-airline'
Plug 'terryma/vim-smooth-scroll'
Plug '42Paris/42header'

call plug#end()
" Configuration pour coc.nvim
" Valider une suggestion avec <Tab>
inoremap <silent><expr> <Tab> pumvisible() ? coc#_select_confirm() : "\<Tab>" 
" Pour déclencher manuellement l'autocomplétion
inoremap <silent><expr> <C-Space> coc#refresh()
highlight Pmenu guibg=#1e1e1e guifg=#d4d4d4
highlight PmenuSel guibg=#44475a guifg=#ffffff
highlight PmenuSbar guibg=#333333
highlight PmenuThumb guibg=#555555
let g:smooth_scroll_mouse = 1
" Ouvrir/fermer NERDTree avec Ctrl+N
map <C-n> :NERDTreeToggle<CR>
let g:user42 = 'ctravers42'
let g:mail42 = 'ctravers@student.42perpignan.fr'
let g:coc_disable_diagnostic = 1

