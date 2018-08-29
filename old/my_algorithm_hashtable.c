
typedef struct nlist{  /* table entry */
    struct nlist *next;  /* net entry in chain */
    char *name;  /* defined name */
    char * defn; /* replacement text */
} listnode;

#define HASHSIZE 101
#define MULTIPIER 31
#define MAX_BUCKETS 1000
listnode *hashtable[HASHSIZE];  /* pointer table */


/* hash: form hash value for string s */
unsigned long hash(char *s){
    unsigned long hashval = 0;
    while(*s)
    {
        hashval = *s + 31*MULTIPIER;
        s++;
    }
    return hashval%MAX_BUCKETS;
}

/*
 The hashing process produces a starting index in the array hashtab;
 if the string is to be found anywhere,
 it will be in the list of blocks beginning there.
 The search is performed by lookup.
 If lookup finds the entry already present,
 it returns a pointer to it; if not, it returns NULL
 */
/* lookup: look for s in hashtable */
struct nlist *lookup(char *s)
{
    listnode *np;
    for(np=hashtable[hash(s)]; np != NULL; np = np->next)
        if(strcmp(s, np->name) == 0)  // find string
            return np;  // find, return the pointer
    // not find, return null
    return NULL;
}

/* make a duplicate of s */
char *strdup(const char* s){
    char *p;
    
    p = (char*) malloc(strlen(s)+1);  /* +1 for '\0\ */
    if( p!=NULL)
        strcpy(p, s);
    
    return p;
}

/*
 install uses lookup to determine whether the name being installed is already present;
 if so, the new definition will supersede the old one.
 Otherwise, a new entry is created.
 install returns NULL if for any reason there is no room for a new entry.
 */
/* install: put(name, defn) in hashtable */
struct nlist *install(char *name, char*defn)
{
    struct nlist *np;
    unsigned long hashval;
    
    if ( (np = lookup(name)) == NULL)  // not found
    {
        //try to add a new
        np = (listnode *) malloc (sizeof(listnode));
        if( np == NULL || (np->name = strdup(name)) == NULL)  // if no space
            return NULL;
        
        hashval = hash(name);
        np->next = hashtable[hashval];  //add the new node to the list top
        hashtable[hashval] = np;
    }
    else  //already there
    {
        free((void*)np->defn);  //free previous defn
    }
    
    if((np->defn = strdup(defn))==NULL)
        return NULL;
    
    return np;
}
