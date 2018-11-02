#define VARA 30 //defines width of car's in +-x
#define VARB 60 //defines length of car
#define VARZ 30 //defines width of the ocar
#define BEHIND 200//defines the size of green background
#define WALK 50//defines the size of roadside walkway
#define MAX_MAX_OCAR 50 //defines the maximum array size for ocar variable
#define OCAR_MIN_SEC 10 //used for defining ocar speed
#define OCAR_MAX_SEC 20 //used for defining ocar speed
#define PADDING_BELOW 30 //defines how much distance of car from lower panel of screen

extern double width, height, WL, WR;
extern double seg_len;
extern int game_state;
//Main car Variables
extern bool car_left, car_right;
extern int car_x, car_y;
extern int FPS, UNIT_MOVE;
//ocar Variables
extern float ocar_pos[MAX_MAX_OCAR][2];
extern bool ocar_present[MAX_MAX_OCAR],ocar_shape[MAX_MAX_OCAR];
extern int MAX_OCAR, OCAR_COUNT, ocar_speed[MAX_MAX_OCAR], ocar_color[MAX_MAX_OCAR][3];
//Score Variables
extern int curr_score,high_score;


