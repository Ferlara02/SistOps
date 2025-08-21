#include <stdbool.h>
#include <stdio.h>
#include <glib.h>
#include "command.h"

struct scommand_s 
    {
        GList *args;
        char *redir_in;
        char *redir_out;
    };

    
scommand scommand_new(void) 
    {
        scommand result= malloc( sizeof(struct scommand_s));
        result->args=NULL;
        result->redir_in=NULL;
        result->redir_out=NULL;
    
        return result;
    }
    
    scommand scommand_destroy(scommand self)
    {
        if (self->args != NULL)
        {
        }
        
        if (self->redir_in != NULL)
        {
        }
        
        if (self->redir_out != NULL)
        {
        }
        
        free(self->args);
        free(self->redir_in);
        free(self->redir_out);
        self->args = NULL;
        self->redir_in=NULL;
        self->redir_out=NULL;
    
        free(self);
    
        self = NULL;
    
        return self;
    }
    
    void scommand_push_back(scommand self, char * argument)
    {
        self->args=g_list_append(self->args, argument);
    }
    
    void scommand_set_redir_in(scommand self, char * filename)
    {
        self->redir_in=filename;
    }
    
    void scommand_set_redir_out(scommand self, char * filename)
    {
        self->redir_out=filename;
    }
   




scommand scommand_destroy(scommand self){

}

void scommand_push_back(scommand self, char * argument){

}
void scommand_pop_front(scommand self){

}
void scommand_set_redir_in(scommand self, char * filename){

}
void scommand_set_redir_out(scommand self, char * filename) {

}
bool scommand_is_empty(const scommand self){

}


unsigned int scommand_length(const scommand self){

}
char * scommand_front(const scommand self){

}
char * scommand_get_redir_in(const scommand self){

}
char * scommand_get_redir_out(const scommand self){

}

char * scommand_to_string(const scommand self){

}


struct pipeline_s
{
    GList scommands;
    bool foreground;
};

pipeline pipeline_new(void)
{
    pipeline result = malloc(sizeof(struct pipeline_s));
    result->foreground = true;
    result->scommands = 
}

pipeline pipeline_destroy(pipeline self)
{

}

void pipeline_push_back(pipeline self, scommand sc);


void pipeline_pop_front(pipeline self);

void pipeline_set_wait(pipeline self, const bool w);

bool pipeline_is_empty(const pipeline self);


unsigned int pipeline_length(const pipeline self);

scommand pipeline_front(const pipeline self);

bool pipeline_get_wait(const pipeline self);


char * pipeline_to_string(const pipeline self);
