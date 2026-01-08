# Copyright (c) 2024 The Chromium Embedded Framework Authors. All rights
# reserved. Use of this source code is governed by a BSD-style license that
# can be found in the LICENSE file.

workspace(name = "cef-project")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "gmp",
    build_file = "//bazel:gmp.BUILD",
    sha256 = "258e6cd51b3fbdfc185c716d55f82c08aff57df0c6fbd143cf6ed561267a1526",
    strip_prefix = "gmp-6.2.0",
    urls = [
        "https://ftp.gnu.org/gnu/gmp/gmp-6.2.0.tar.xz",
        "https://mirrors.kernel.org/gnu/gmp/gmp-6.2.0.tar.xz",
        "https://mirror.koddos.net/gnu/gmp/gmp-6.2.0.tar.xz",
    ],
)

#
# Load the CEF binary distribution.
#

# Download, extract and load the distribution.
load("//bazel/cef:loader.bzl", "load_cef_repo")
load_cef_repo()

# To load a locally downloaded/extracted distribution use the following
# lines instead:
# load("//bazel/cef:loader.bzl", "load_local_cef_repo")
# load_local_cef_repo(path = "third_party/cef")

#
# Windows configuration.
#

# Configure windows SDK.
load("@cef//bazel/win:setup_sdk.bzl", "setup_sdk")
setup_sdk(name = "winsdk")

#
# Linux configuration.
#

# Configure Linux using pkg-config.
load("//bazel:external_local_repository.bzl", "external_local_repository")
external_local_repository(
    name="pkg_config",
    path="@cef//bazel/linux/pkg_config"
)
load("@pkg_config//:pkg_config.bzl", "pkg_config")

# Define packages used by @cef//tests/cefclient.

pkg_config(
    name = "gmodule2",
    pkg_name = "gmodule-2.0",
)

pkg_config(
    name = "gtk3",
    pkg_name = "gtk+-3.0",
)

pkg_config(
    name = "gthread2",
    pkg_name = "gthread-2.0",
)

pkg_config(
    name = "gtkprint3",
    pkg_name = "gtk+-unix-print-3.0",
)

pkg_config(
    name = "xi",
)

# Define packages used by @cef//tests/ceftests.

pkg_config(
    name = "glib2",
    pkg_name = "glib-2.0",
)

