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

" Compplete me
Plug 'neovim/nvim-lspconfig'
" Plug 'williamboman/mason.nvim', { 'do': ':MasonUpdate' }
Plug 'hrsh7th/cmp-nvim-lsp'
Plug 'hrsh7th/cmp-buffer'
Plug 'hrsh7th/cmp-path'
Plug 'hrsh7th/cmp-cmdline'
Plug 'hrsh7th/nvim-cmp'

" List ends here. Plugins become visible to Vim after this call.
call plug#end() 

" nvim-cmp setup
" set completeopt=menu,menuone,noselect

lua <<EOF
  -- Set up nvim-cmp.
  local cmp = require'cmp'

  cmp.setup({
    snippet = {
      -- REQUIRED - you must specify a snippet engine
      expand = function(args)
        vim.fn["vsnip#anonymous"](args.body) -- For `vsnip` users.
        -- require('luasnip').lsp_expand(args.body) -- For `luasnip` users.
        -- require('snippy').expand_snippet(args.body) -- For `snippy` users.
        -- vim.fn["UltiSnips#Anon"](args.body) -- For `ultisnips` users.
      end,
    },
    window = {
      -- completion = cmp.config.window.bordered(),
      -- documentation = cmp.config.window.bordered(),
    },
    mapping = cmp.mapping.preset.insert({
      ['<C-b>'] = cmp.mapping.scroll_docs(-4),
      ['<C-f>'] = cmp.mapping.scroll_docs(4),
      ['<C-Space>'] = cmp.mapping.complete(),
      ['<C-e>'] = cmp.mapping.abort(),
      ['<CR>'] = cmp.mapping.confirm({ select = true }), -- Accept currently selected item. Set `select` to `false` to only confirm explicitly selected items.
    }),
    sources = cmp.config.sources({
      { name = 'nvim_lsp' },
      { name = 'vsnip' }, -- For vsnip users.
      -- { name = 'luasnip' }, -- For luasnip users.
      -- { name = 'ultisnips' }, -- For ultisnips users.
      -- { name = 'snippy' }, -- For snippy users.
    }, {
      { name = 'buffer' },
    })
  })

  -- Set configuration for specific filetype.
  cmp.setup.filetype('gitcommit', {
    sources = cmp.config.sources({
      { name = 'cmp_git' }, -- You can specify the `cmp_git` source if you were installed it.
    }, {
      { name = 'buffer' },
    })
  })

  -- Use buffer source for `/` and `?` (if you enabled `native_menu`, this won't work anymore).
  cmp.setup.cmdline({ '/', '?' }, {
    mapping = cmp.mapping.preset.cmdline(),
    sources = {
      { name = 'buffer' }
    }
  })

  -- Use cmdline & path source for ':' (if you enabled `native_menu`, this won't work anymore).
  cmp.setup.cmdline(':', {
    mapping = cmp.mapping.preset.cmdline(),
    sources = cmp.config.sources({
      { name = 'path' }
    }, {
      { name = 'cmdline' }
    })
  })

  -- Set up mason.nvim
  require("mason").setup()
  -- Set up lspconfig.
  local capabilities = require('cmp_nvim_lsp').default_capabilities()
  -- Replace <YOUR_LSP_SERVER> with each lsp server you've enabled.
  require('lspconfig')['pyright'].setup {
    capabilities = capabilities
  }
  require('lspconfig')['bashls'].setup{}
  require('lspconfig')['r_language_server'].setup{}
EOF

>lua
    require("mason").setup()
<


" lua <<EOF
"  -- Setup nvim-cmp.
"  local cmp = require'cmp'
"
"  cmp.setup({
"    snippet = {
"      -- REQUIRED - you must specify a snippet engine
"      expand = function(args)
"        vim.fn["vsnip#anonymous"](args.body) -- For `vsnip` users.
"        -- require('luasnip').lsp_expand(args.body) -- For `luasnip` users.
"        -- vim.fn["UltiSnips#Anon"](args.body) -- For `ultisnips` users.
"        -- require'snippy'.expand_snippet(args.body) -- For `snippy` users.
"      end,
"    },
"    mapping = {
"      -- ['<C-p>'] = cmp.mapping.select_prev_item(),
"      -- ['<C-n>'] = cmp.mapping.select_next_item(),
"      -- Add tab support
"      ['<S-Tab>'] = cmp.mapping.select_prev_item(),
"      ['<Tab>'] = cmp.mapping.select_next_item(),
"      ['<C-b>'] = cmp.mapping(cmp.mapping.scroll_docs(-4), { 'i', 'c' }),
"      ['<C-f>'] = cmp.mapping(cmp.mapping.scroll_docs(4), { 'i', 'c' }),
"      ['<C-Space>'] = cmp.mapping(cmp.mapping.complete(), { 'i', 'c' }),
"      ['<C-y>'] = cmp.config.disable, -- Specify `cmp.config.disable` if you want to remove the default `<C-y>` mapping.
"      ['<C-e>'] = cmp.mapping({
"        i = cmp.mapping.abort(),
"        c = cmp.mapping.close(),
"      }),
"      -- Accept currently selected item. If none selected, `select` first item.
"      -- Set `select` to `false` to only confirm explicitly selected items.
"      ['<CR>'] = cmp.mapping.confirm({ select = true }),
"    },
"    sources = cmp.config.sources({
"      { name = 'nvim_lsp' },
"      { name = 'vsnip' }, -- For vsnip users.
"      -- { name = 'luasnip' }, -- For luasnip users.
"      -- { name = 'ultisnips' }, -- For ultisnips users.
"      -- { name = 'snippy' }, -- For snippy users.
"      { name = 'buffer' },
"      { name = 'path' },
"        })
"    })

"  -- Use buffer source for `/` (if you enabled `native_menu`, this won't work anymore).
"  cmp.setup.cmdline('/', {
"    sources = {
"      { name = 'buffer' }
"    }
"  })

"  -- Use cmdline & path source for ':' (if you enabled `native_menu`, this won't work anymore).
"  cmp.setup.cmdline(':', {
"    sources = cmp.config.sources({
"      { name = 'path' }
"    }, {
"      { name = 'cmdline' }
"    })
"  })

"  -- Setup lspconfig.
"  local capabilities = require('cmp_nvim_lsp').update_capabilities(vim.lsp.protocol.make_client_capabilities())
"  require('lspconfig').pyright.setup {capabilities = capabilities}
"  require('lspconfig').r_language_server.setup{capabilities = capabilities}
"  require('lspconfig').bashls.setup{capabilities = capabilities}
"EOF


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

" vim-slime
" let g:slime_target = "tmux"
" let g:slime_python_ipython = 1
" let g:slime_default_config = {"socket_name": "default", "target_pane": "{right-of}"}

" nerdcommenter
let g:NERDSpaceDelims = 1
let g:NERDCustomDelimiters = {'python': {'left': '#'}}
let NERDDefaultAlign="left"

" Snakemake
 au BufNewFile,BufRead *.snake set syntax=snakemake
