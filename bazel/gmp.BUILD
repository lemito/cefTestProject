load("@rules_cc//cc:defs.bzl", "cc_library")

# Minimal config.h for Windows
genrule(
    name = "config_h",
    outs = ["config.h"],
    cmd = """
cat > $@ << 'EOF'
#define HAVE_STDINT_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_LIMITS_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define SIZEOF_VOID_P 8
#define SIZEOF_UNSIGNED_LONG 4
#define SIZEOF_UNSIGNED_LONG_LONG 8
#define GMP_LIMB_BITS 64
#define GMP_NAIL_BITS 0
#define WANT_ASSERT 1
EOF
""",
)

cc_library(
    name = "gmp",
    srcs = [
        "assert.c",
        "compat.c",
        "errno.c",
        "extract-dbl.c",
        "invalid.c",
        "memory.c",
        "mp_bpl.c",
        "mp_clz_tab.c",
        "mp_dv_tab.c",
        "mp_get_fns.c",
        "mp_minv_tab.c",
        "mp_set_fns.c",
        "nextprime.c",
        "primesieve.c",
        "tal-reent.c",
        "version.c",
    ] + glob([
        "mpz/*.c",
        "mpn/generic/*.c",
    ]),
    hdrs = [
        "gmp.h",
        "gmp-impl.h",
        "longlong.h",
        ":config_h",
    ],
    includes = ["."],
    visibility = ["//visibility:public"],
    copts = [
        "-DHAVE_CONFIG_H",
        "-D__GMP_WITHIN_GMP",
        "-DOPERATION_add_n",
    ],
)