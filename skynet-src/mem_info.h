#ifndef _MEM_INFO_H_
#define _MEM_INFO_H_

#include <stdalign.h>
#include <stddef.h>

#include "atomic.h"

#define CACHE_LINE_SIZE 64

#if defined(_MSC_VER)
#define ALIGN_AS(x) __declspec(align(x))
#define ALIGNOF(x) __alignof(x)
#define STATIC_ASSERT(cond, msg) static_assert(cond, msg)
#else
#define ALIGN_AS(x) alignas(x)
#define ALIGNOF(x) alignof(x)
#define STATIC_ASSERT(cond, msg) _Static_assert(cond, msg)
#endif

typedef struct {
    size_t alloc;
    size_t alloc_count;
    size_t free;
    size_t free_count;
} MemInfo;

typedef struct {
    // alloc 与 free 可能不在一个线程
    // 为了避免竞争，这里也拆成两个 CacheLine 大小
    ALIGN_AS(CACHE_LINE_SIZE)
    ATOM_SIZET alloc;
    ATOM_SIZET alloc_count;

    ALIGN_AS(CACHE_LINE_SIZE)
    ATOM_SIZET free;
    ATOM_SIZET free_count;
} AtomicMemInfo;

void meminfo_init(MemInfo *info);
void atomic_meminfo_init(AtomicMemInfo *info);

void meminfo_alloc(MemInfo *info, size_t size);
void atomic_meminfo_alloc(AtomicMemInfo *info, size_t size);

void meminfo_free(MemInfo *info, size_t size);
void atomic_meminfo_free(AtomicMemInfo *info, size_t size);

void meminfo_merge(MemInfo *dest, const MemInfo *src);
void atomic_meminfo_merge(MemInfo *dest, const AtomicMemInfo *src);

#endif // _MEM_INFO_H_
