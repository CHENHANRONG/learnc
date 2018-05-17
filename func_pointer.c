enum TYPE{SQUARE, RECT, CIRCLE, POLYGON};
struct shape{
    float params[MAX];
    enum TYPE type;
};

void draw_square(struct shape* ps);
void draw_rec(struct shape* ps);
void draw_circle(struct shape* ps);
void draw_poly(struct shape* ps);
void (*fp[4])(struct shape* ps)= {&draw_square ,&draw_rec ,& draw_circle ,& draw_poly};
void draw(struct shape* ps){
    (*fp[ps->type]) ( ps ) ;
//    switch(ps->type){
//        case SQUARE:
//            fp[0](ps);
//            break;
//        case RECT:
//            fp[1](ps);
//            break;
//        case CIRCLE:
//            fp[2](ps);
//            break;
//        case POLYGON:
//            fp[3](ps);
//            break;
//        default:
//           ;
//    }
}
