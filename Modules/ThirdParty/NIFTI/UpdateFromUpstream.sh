#!/usr/bin/env bash

set -e
set -x
shopt -s dotglob

readonly name="nifti"
readonly ownership="NIFTI Upstream <nifti@github.com>"
readonly subtree="Modules/ThirdParty/NIFTI/src/nifti"
readonly repo="https://github.com/NIFTI-Imaging/nifti_clib.git"
readonly tag="v3.0.1"
readonly shortlog=false
readonly paths="
CMakeLists.txt
CTestConfig.cmake
LICENSE
README.md
cmake
znzlib
niftilib
"

extract_source () {
    git_archive
}

. "${BASH_SOURCE%/*}/../../../Utilities/Maintenance/update-third-party.bash"
