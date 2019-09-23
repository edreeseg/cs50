# Questions

## What's `stdint.h`?

`stdint.h` is a header file that we can import for access to types such as `uint8_t` - integer data types that are a specific size.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The point of these data types would be to specifically identify exactly how large each integer will be, so as to avoid any issues that may come from using a more general data type.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE - 1 byte
DWORD - 4 bytes
LONG - 4 bytes
WORD - 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes would be part of the file's BITMAPFILEHEADER - according to the chart provided, it would specifically be the file's `bfType`.  According to outside research, for a BMP file these first two bytes would represent the characters 'B' and 'M'.

## What's the difference between `bfSize` and `biSize`?

`bfSize` is part of the BITMAPFILEHEADER, whereas `biSize` is part of the BITMAPINFOHEADER.

## What does it mean if `biHeight` is negative?

This means that it is a top-down DIB (Device-Independent Bitmap), and its origin is the top-left corner.  Top-down DIBs cannot be compressed.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

fopen returns a NULL pointer if it fails to retrieve a pointer to the file.  This could perhaps happen if it was passed an invalid path.

## Why is the third argument to `fread` always `1` in our code?

We pass in `1` because we only want to read one element from the file, with a size equal to the argument passed to the `size` parameter.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

It would be assigned a value of `3`.

`sizeof(RGBTRIPLE)` would be `3`.

`(4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4`
`(4 - 9 % 4) % 4`
`(4 - 1) % 4`
`3 % 4`
`3`

## What does `fseek` do?

`fseek` allows you to move the file pointer to a specific position.

## What is `SEEK_CUR`?

`SEEK_CUR` is a constant associated with the `fseek` function that tells it to move pointer to the provided location.
