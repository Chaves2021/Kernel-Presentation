# Kernel-Presentation
Repo with the content of my kernel exploit presentation

**Strongly based on the [pwnkernel enviroment made by pwncollege](https://github.com/pwncollege/pwnkernel)**

## How to use:

Build the kernel, busybox, and demo modules (need to add the modules yet):

* If you use Debian/Ubuntu based distro
<pre><code>$ ./ubuntu_build.sh</code></pre>
* ~~If you use Arch based distro~~
~~<pre><code>$ ./arch_build.sh</code></pre>~~

**OBS:** the arch version is not working due the gcc version of arch distros, already tried to apply force_order.patch in the repo [based on this patch](https://patchwork.kernel.org/project/linux-kbuild/patch/20200903203053.3411268-3-samitolvanen@google.com/) but did not work.

Run the kernel:

<pre><code>$ ./launch.sh</code></pre>

All modules will be in /, ready to be inserted, and the host's home directory will be mounted as /home/ctf in the guest.
