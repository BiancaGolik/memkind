/*
 * Copyright (C) 2014, 2015 Intel Corporation.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice(s),
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice(s),
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO
 * EVENT SHALL THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <memkind.h>
#include <memkind_default.h>
#include <gtest/gtest.h>

extern const struct memkind_ops MEMKIND_BAD_OPS[];
extern const size_t MEMKIND_BAD_OPS_LEN;

class MemkindCreate: public :: testing :: Test { };

TEST_F(MemkindCreate, bad_ops)
{
    size_t i;
    int err;
    memkind_t kind;
    for (i = 0; i < MEMKIND_BAD_OPS_LEN; ++i) {
        err = memkind_create(MEMKIND_BAD_OPS + i, "bad_ops", &kind);
        EXPECT_TRUE(err == MEMKIND_ERROR_BADOPS);
        EXPECT_TRUE(kind == NULL);
    }
}

TEST_F(MemkindCreate, rep_name)
{
    int i, err;
    int num_bad_ops = sizeof(*MEMKIND_BAD_OPS)/sizeof(memkind_ops);
    memkind_t kind;
    for (i = 0; i < num_bad_ops; ++i) {
        err = memkind_create(&MEMKIND_DEFAULT_OPS, "memkind_default", &kind);
        EXPECT_TRUE(err == MEMKIND_ERROR_REPNAME);
        EXPECT_TRUE(kind == NULL);
    }
}
