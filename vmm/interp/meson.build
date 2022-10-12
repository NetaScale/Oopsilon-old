flex = find_program('flex', required: true)
bison = find_program('bison', required: true)

lgen = generator(flex,
    output : ['@PLAINNAME@.cc', '@PLAINNAME@.hh'],
    arguments : ['-o', '@OUTPUT0@', '--header-file=@OUTPUT1@', '@INPUT@'])

pgen = generator(bison,
    output : ['@BASENAME@.tab.cc', '@BASENAME@.tab.hh'],
    arguments : ['@INPUT@', '--verbose', '-Wall', '--defines=@OUTPUT1@',
        '--output=@OUTPUT0@'])

vmm_src += [lgen.process('scanner.l'), pgen.process('parser.yy')]
