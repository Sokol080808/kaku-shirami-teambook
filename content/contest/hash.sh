# Hashes a file, ignoring all whitespace and comments. 
# Use for verifying that code was correctly typed.
# Apple cpp does not support -fpreprocessed; Homebrew installs GNU cpp
# with a version suffix. CPP can also select a specific executable.
if [ -z "${CPP:-}" ]; then
    for candidate in cpp cpp-20 cpp-19 cpp-18 cpp-17 cpp-16 cpp-15 cpp-14 cpp-13 cpp-12 cpp-11 cpp-10; do
        if command -v "$candidate" >/dev/null 2>&1 &&
            "$candidate" -dD -P -fpreprocessed </dev/null >/dev/null 2>&1; then
            CPP=$candidate
            break
        fi
    done
fi
if [ -z "${CPP:-}" ]; then
    echo "GNU cpp is required for code checksums; install GCC or set CPP." >&2
    exit 1
fi
code=$("$CPP" -dD -P -fpreprocessed) || exit 1
printf '%s' "$code" | tr -d '[:space:]' | md5sum | cut -c-6
