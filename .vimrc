" Plugins will be downloaded under the specified directory.
call plug#begin('~/.vim/plugged')

" Declare the list of plugins.
Plug 'vim-scripts/indentpython.vim'
Plug 'vim-syntastic/syntastic'
Plug 'scrooloose/nerdcommenter'
Plug 'jiangmiao/auto-pairs'
Plug 'burneyy/vim-snakemake'
Plug 'crusoexia/vim-monokai'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'

" List ends here. Plugins become visible to Vim after this call.
call plug#end() 


" User define
set t_Co=256
syntax on
colorscheme monokai

set encoding=utf-8
set splitbelow
set splitright
set tabstop=4
set shiftwidth=4
set expandtab
set ai
set nu
set confirm
set ignorecase
set hlsearch
set incsearch

" syntastic
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 0
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0
let g:syntastic_python_checkers = ['flake8']
let g:syntastic_python_flake8_args = '--ignore=E309,E501,E302,E305'
" let g:syntastic_python_python_exec = 'python3'
highlight SyntasticError ctermbg=lightmagenta ctermfg=black
highlight SyntasticWarning ctermbg=lightyellow ctermfg=black

let g:slime_default_config = {"socket_name": "default", "target_pane": "{right-of}"}

" nerdcommenter
let g:NERDSpaceDelims = 1
let g:NERDCustomDelimiters = {'python': {'left': '#'}}
let NERDDefaultAlign="left"

" Snakemake
 au BufNewFile,BufRead *.snake set syntax=snakemake
