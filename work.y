
%{
    %}
    %union {
            int deepth;
    }
%%
S->(ML) {}
M->     {$$.deepth=}
S->a    {printf("deepth: %d\n",$$.deepth)}
L->L,S {$}
L->S   {}