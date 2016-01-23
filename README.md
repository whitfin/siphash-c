# SipHash

[![Build Status](https://travis-ci.org/zackehh/siphash-c.svg?branch=master)](https://travis-ci.org/zackehh/siphash-c)

A C89 implementation of the SipHash cryptographic hash family. Supports any variation, although defaults to the widely used SipHash-2-4.

This library was heavily influenced by [veorq's C implementation](https://github.com/veorq/siphash), but modified to be made a little more user-friendly (IMO).

## Usage

You can use this library as either an extension of your own project, or via the command line using a wrapper.

### Library Setup

This project provides [clib](https://github.com/clibs/clib) friendly configurations, so it should be easy to pull into your project.

If you're intending to use this project from another project, simply grab it from clib:

```bash
$ clib install zackehh/siphash-c
```

This will place it into `./deps`, and from there you can just include it. You can always just include it manually, too.

From there it's pretty simple to use; you just provide a 16-byte key, some input data, and the rounds of compression to use (if you dunno what to do for these, use 2 and 4).

```c
char key[16] = "0123456789ABCDEF";
char data[]  = "hello";
int c = 2, d = 4;

uint64_t output = siphash(key, data, c, d);
```

If you provide a key larger than 16 bytes, we'll simply use the first 16. This is slightly riskier but it saves time measuring the key and error handling.

### Command Line Setup

At the moment, clib doesn't support both executables and source files in the same project so you have to build manually if you want to create the command line interface:

```bash
$ cd /tmp
$ git clone https://github.com/zackehh/siphash-c.git
$ cd siphash-c
$ make install
```

From there you can access `siphash` through your terminal, as follows:

```bash
$ siphash -k "0123456789ABCDEF" -i "hello" -c 2 -d 4
```

The applicable options exist of:

- `-k` - the key to use for the hash (required)
- `-i` - the input string to hash    (required)
- `-f` - a file path to hash
- `-c` - the rounds of C compression (defaults to c)
- `-d` - the rounds of D compression (defaults to 4)

Note:

- `-k` must be provided, along with either of `-i` or `-f`.
- Be careful when using `-f`, as the file input is buffered into memory.
- Avoid adventurous use cases, this is a tool designed for debugging rather than heavy use.

## Testing

The tests are very barebones at the moment, but you can run them as follows:

```c
$ make siphash_test
$ ./build/test/siphash_test
```