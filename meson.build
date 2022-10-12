project('Oopsilon', ['c', 'cpp'], default_options: [ 'cpp_std=c++20' ])

arch = get_option('arch')

# this is only needed for arch=amd64
executable('limine-deploy', 'limine/limine-deploy.c', native: true)

subdir('vmm')
