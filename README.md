# Kernel-Presentation
Repo with the content of my kernel exploit presentation

**Strongly based on the [pwnkernel enviroment made by pwncollege](https://github.com/pwncollege/pwnkernel)**

## How to use:

Build the kernel, busybox, and demo modules (need to add the modules yet):

* If you use Debian/Ubuntu based distro
<pre><code>$ ./ubuntu_build.sh</code></pre>
* If you use Arch based distro
<pre><code>$ ./arch_build.sh</code></pre>

Run the kernel:

<pre><code>$ ./launch.sh</code></pre>

All modules will be in /, ready to be inserted, and the host's home directory will be mounted as /home/ctf in the guest.
