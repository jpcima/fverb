# fverb

A stereo variant of the reverberator by Jon Dattorro

```
Dattorro, Jon. "Effect design, part 1: Reverberator and other filters."
Journal of the Audio Engineering Society 45.9 (1997): 660-684.
```

## Build instructions

1. Obtain prerequisites

Install needed packages:

- `git`
- `build-essential`
- `pkg-config`

2. Check out the repository and submodules

```
git clone https://github.com/jpcima/fverb.git
cd fverb
git submodule update --init
```

3. Compile

```
make
```

4. Install

To perform a system-wide installation:
```
sudo make install
```

Or, to install only for the current user:
```
make install-user
```
