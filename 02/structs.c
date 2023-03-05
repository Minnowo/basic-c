

// https://www.cs.swarthmore.edu/~newhall/cs31/resources/C-structs_pointers.php

#include <stdio.h>
#include <stdlib.h>

#define RANDOM(seed, max) ((((seed * 122) >> 2) + seed - ((seed *229) % (1 + (int)seed/6)))% max)

// // am a really big fan of the preprocessor it's epic
// #define DEBUG 0



typedef unsigned char byte;

typedef struct ARGB{
    byte a;
    byte r;
    byte g;
    byte b;
} ARGB;

typedef struct {
    ARGB* pixels;
    unsigned int width;
    unsigned int height;
} Image;

void print_argb(ARGB* argb)
{
    printf("%d %d %d %d\n", argb->a, argb->r, argb->g, argb->b);
}


void free_image(Image* bitmap)
{
    // am i doing this right??
    // almost forgot about the pixels array being malloced 
    // class c forgetting memory 
    free(bitmap->pixels);
    free(bitmap);
}


Image* get_empty(unsigned int width, unsigned int height)
{
    Image* bitmap = malloc(sizeof(Image));

    if(bitmap == NULL)
    {
        return NULL;
    }

    bitmap->pixels = malloc(sizeof(ARGB) * width * height);

    if(bitmap->pixels == NULL)
    {
        free(bitmap);
        return NULL;
    }

    bitmap->width = width;

    bitmap->height = height;

    return bitmap;
}


void fill_random(Image *bitmap, long long seed)
{
    long long start = RANDOM(seed, 256);

    // you can manipulate the *ARGB pointer to point to a single byte
    // and then access individual argb bytes in the image using it 
    byte* raw = (byte*)bitmap->pixels;

    for(int i = 0; i < 4 * bitmap->width * bitmap->height; i += 4)
    {
        // a
        start = RANDOM(start, 256);
        raw[i + 0] = start;

#ifdef DEBUG
        printf("[%d] %lld\n", i, start);
#endif
        
        // r
        start = RANDOM(start, 256);
        raw[i + 1] = start;
#ifdef DEBUG
        printf("[%d] %lld\n", i, start);
#endif
        
        // g
        start = RANDOM(start, 256);
        raw[i + 2] = start;
        
#ifdef DEBUG
        printf("[%d] %lld\n", i, start);
#endif

        // b
        start = RANDOM(start, 256);
        raw[i + 3] = start;
#ifdef DEBUG
        printf("[%d] %lld\n", i, start);
#endif
    }
}

int main(int argc, char** argv) 
{
    unsigned int width  = 10000;
    unsigned int height = 10000;
    
    printf("Generating image of size %d x %d -> %d bytes\n", width, height, width*height);

    Image* a = get_empty(width, height);

    if(a == NULL)
    {
        printf("Could not generate empty image\n");
        return 1;
    }

    // fill_random(a, 22);
    
    // for(int i = 0; i < width * height; i ++)
    // {
    //     print_argb(a->pixels + i);
    // }


    printf("hit 5 to free memory\n");
    int c;
    scanf("%d", &c);

    // i wanna see the memory alloc in htop
    free_image(a);

    printf("hit 5 to exit\n");

    scanf("%d", &c);

    return 0;
}