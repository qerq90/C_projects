#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int count;
  char *w;
  struct node *left;
  struct node *right;
} NODE;

int get_word(FILE *fp, unsigned char *word)
{
    unsigned char c;
    int flag = 1;
    int word_length = 0;

    while(flag < 10)
    {
        c = fgetc(fp);
        if(c == 255) flag++;
        if(c != 255) flag--;

        if(c < 65 || (c > 90 && c < 97) || (c > 122 && c < 192))
        {
            if(word_length > 0)
            {
                *(word + word_length) = '\0';
                return 1;
            }

            continue;
        }

        if(c <= 90) c += 32;
        if(c <= 223 && c >= 192) c += 32;
        *(word + word_length) = c;
        word_length++;
    }

    return 0;
}

NODE *root = NULL;

int leftMoreThanRight(unsigned char *string1, unsigned char *string2)
{   
    int i = 0;

    while(*(string1 + i) && *(string2 + i))
    {
        if(*(string1 + i) < *(string2 + i))
        {
            return 0;
        }

        if(*(string1 + i) > *(string2 + i))
        {
            return 1;
        }

        i++;
    }

    return -1;
}

NODE *add(NODE *root, NODE *r, unsigned char *string)
{
    if(!r) 
    {
        r = (NODE*)malloc(sizeof(NODE));
        r->count = 1;
        
        r->w = malloc(sizeof(char) * 35);
        strcpy(r->w, string);

        r->right = NULL;
        r->left = NULL;
        if(!root) return r;

        int result = leftMoreThanRight(root->w, string);

        if(result)
        {
            root->left = r;
        } else {
            root->right = r;
        }

        return r;
    } else {
        int result = leftMoreThanRight(r->w, string);
        
        if(result == -1)
        {
            r->count++;
            return root;
        }

        if(!result)
        {
            add(r, r->right, string);
        }

        if(result)
        {
            add(r, r->left, string);
        }

        return root;
    }
}

void writeToFile(FILE *fp, NODE *node)
{
    fprintf(fp, "%s %d\n", node->w, node->count);
}

void writeTreeFile(FILE *fp, NODE *root)
{
    if(root->left != NULL)
    {
        writeTreeFile(fp, root->left);
    }
    
    writeToFile(fp, root);

    if(root->right != NULL)
    {
        writeTreeFile(fp, root->right);
    }


}

int main(int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        FILE *fp;
        fp = fopen(argv[i], "r");
        unsigned char *word = malloc(sizeof(char) * 35);

        while(get_word(fp, word))
        {
            root = add(root, root, word);
        }

        free(word);

        fclose(fp);
    }

    FILE *fp = fopen("result.txt", "w");

    writeTreeFile(fp, root);

    fclose(fp);

	return 0;
}