" Plugins will be downloaded under the specified directory.
call plug#begin(stdpath('data') . '/plugged')

" Theme
Plug 'patstockwell/vim-monokai-tasty'
Plug 'nvim-lualine/lualine.nvim'
" Coding utilities
Plug 'lukas-reineke/indent-blankline.nvim'
Plug 'windwp/nvim-autopairs'
Plug 'scrooloose/nerdcommenter'
" LSP
Plug 'neovim/nvim-lspconfig'
Plug 'williamboman/mason.nvim', { 'do': ':MasonUpdate' }
" Completion
Plug 'hrsh7th/cmp-nvim-lsp'
Plug 'hrsh7th/cmp-buffer'
Plug 'hrsh7th/cmp-path'
Plug 'hrsh7th/cmp-cmdline'
Plug 'hrsh7th/nvim-cmp'
Plug 'hrsh7th/cmp-vsnip'
Plug 'hrsh7th/vim-vsnip'

" List ends here. Plugins become visible to Vim after this call.
call plug#end() 


" User define Vim config
syntax on
set t_Co=256
colorscheme vim-monokai-tasty

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

" nerdcommenter
let g:NERDSpaceDelims = 1
let g:NERDCustomDelimiters = {'python': {'left': '#'}}
let NERDDefaultAlign="left"



lua require('init')
