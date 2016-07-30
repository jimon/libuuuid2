# libuuuid2

When I was looking for a some simple library to generate uuid's in a portable fashion I found this options:

- Use libuuid directly, but it's written in a bit strange fashion which hurts its portability.
- Use system provided libs, but there is zero portability.
- Use something like [libuuuid](https://github.com/jpalus/libuuuid), but there are some troubles:
	- It's written such as you need to control which source files you add between platforms
	- No direct access to uuid bytes.
	- Non permissive license.

So here's my take:

- Two files.
- MIT license (this project was inspired but not derived from libuuuid).
- Supports:
	- Windows
	- FreeBSD

---

TODO:
- Generate domain specific uuid's
- Support:
	- Linux
	- OS X

