
ldscript = meson.current_source_dir()/'linker.ld'

kernel_common_args = [ '-ffreestanding', '-fno-stack-protector', '-nostdlib',
    '-fno-stack-check', '-fno-pic', '-fno-pie', '-mabi=sysv', '-mno-red-zone',
    '-mcmodel=kernel', '-D_KERNEL' ]

vmm = executable('vmm', vmm_src, 'kmain.c',
    c_args: kernel_common_args,
    cpp_args: kernel_common_args,
    include_directories: [ '../libcshim', '../interp', '../' ],
    link_args : [ '-nostdlib', '-static',
	  '-Wl,-z,max-page-size=0x1000', '-Wl,--build-id=none',
	  '-Wl,-T' + ldscript ])
