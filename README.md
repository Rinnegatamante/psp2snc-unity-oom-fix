# Premise

psp2snc is the official Sony compiler for PSVita. It is compiled as a 32-bit executable and when exporting Unity games with il2cpp, it can throw a `Fatal Error: Out of memory in mem_alloc`.

This is cause, under certain circumstances, the compiler might end up using more than 3.2GB of RAM and thus exceeding the amount of RAM a 32-bit executable can use.

This small wrapper workaround this issue by relaxing compiler optimizations in order to make it use less RAM.

# Installation instructions

- Download psp2snc.exe from the Release tab.
- Rename your original `psp2snc.exe` executable located in the `sdk/host_tools/build/bin` folder of your SDK install to `psp2snc_real.exe`
- Place in the same folder the downloaded `psp2snc.exe`
