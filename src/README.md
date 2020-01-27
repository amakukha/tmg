Files
--

 - `build.sh` – build script, corresponds to the original `run`.
 - `tmg.sh` – compilation script, corresponds to the original `tmg`.
 - `tmga.c` – main file, corresponds to the original `tmga.s`
 - `tmgb.h` – library of TMG functions, corresponds to the original directory `tmgb`
 - `tmgc.h` – definitions, corresponds to `tmgc.s`
 - `libs.h` – library that allows to swap blocks of memory onto a disk (it was important in PDP-7 days)
 - `tmgl.h` – table which defines how translation is done. This is the only part that gets swapped when a new compiler is being built.

Debugging
--

See `DEBUG_MODE` and `TRACING` macros in tmgc.h.
