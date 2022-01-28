## `modlist` – list KEXTs and their paths on macOS

`kextstat` does not have a way to show paths of loaded KEXTs. This tool lists KEXTs and their paths. It is blatantly stolen from [antek's tech blog](https://anadoxin.org/blog/listing-macos-loaded-kext-paths.html/).

To build, make sure you have CMake and a working compiler. Then run these commands:

```
cmake -B build
cd build
make
```

Now you should be able to run `modlist` from the `build` directory.
