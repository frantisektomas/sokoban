#define KEY_ESCAPE 27

typedef enum {
    IN_KEY_NONE = 0, // unknown or none key
    IN_KEY_F1, // function key F1
    IN_KEY_F2, // function key F2
    IN_KEY_F3, // function key F3
    IN_KEY_F4, // function key F4
    IN_KEY_F5, // function key F5
    IN_KEY_F6, // function key F6
    IN_KEY_F7, // function key F7
    IN_KEY_F8, // function key F8
    IN_KEY_F9, // function key F9
    IN_KEY_F10, // function key F10
    IN_KEY_F11, // function key F11
    IN_KEY_F12, // function key F12
    IN_KEY_ENTER = 13, // enter/send key
    IN_KEY_DOWN, // down-arrow key
    IN_KEY_UP, // up-arrow key
    IN_KEY_LEFT, // left-arrow key
    IN_KEY_RIGHT, // right-arrow key
    IN_KEY_HOME, // home key
    IN_KEY_END, // end key
    IN_KEY_BACKSPACE,// backspace key
    IN_KEY_DELETE, // delete key
    IN_KEY_INSERT, // insert key
    IN_KEY_PAGE_DOWN,// page-down key
    IN_KEY_PAGE_UP, // page-up key
    IN_KEY_TAB, // tab key
    IN_KEY_PRINT, // print key
    IN_KEY_ESCAPE, // escape key
    IN_KEY_CTRL, // control key
    IN_KEY_ALT, // alt key
    IN_KEY_SHIFT, // shift key,
    IN_KEY_SPACE = 32,// backspace key
    IN_KEY_0 = 48, // keys 0 - 9
    IN_KEY_1,
    IN_KEY_2,
    IN_KEY_3,
    IN_KEY_4,
    IN_KEY_5,
    IN_KEY_6,
    IN_KEY_7,
    IN_KEY_8,
    IN_KEY_9,
    
    IN_KEY_A = 65, // keys representing upper case letters
    IN_KEY_B,
    IN_KEY_C,
    IN_KEY_D,
    IN_KEY_E,
    IN_KEY_F,
    IN_KEY_G,
    IN_KEY_H,
    IN_KEY_I,
    IN_KEY_J,
    IN_KEY_K,
    IN_KEY_L,
    IN_KEY_M,
    IN_KEY_N,
    IN_KEY_O,
    IN_KEY_P,
    IN_KEY_Q,
    IN_KEY_R,
    IN_KEY_S,
    IN_KEY_T,
    IN_KEY_U,
    IN_KEY_V,
    IN_KEY_W,
    IN_KEY_X,
    IN_KEY_Y,
    IN_KEY_Z,
    IN_KEY_a = 97, // keys representing lower case letters
    IN_KEY_b,
    IN_KEY_c,
    IN_KEY_d,
    IN_KEY_e,
    IN_KEY_f,
    IN_KEY_g,
    IN_KEY_h,
    IN_KEY_i,
    IN_KEY_j,
    IN_KEY_k,
    IN_KEY_l,
    IN_KEY_m,
    IN_KEY_n,
    IN_KEY_o,
    IN_KEY_p,
    IN_KEY_q,
    IN_KEY_r,
    IN_KEY_s,
    IN_KEY_t,
    IN_KEY_u,
    IN_KEY_v,
    IN_KEY_w,
    IN_KEY_x,
    IN_KEY_y,
    IN_KEY_z
} INPUT_KEY;

INPUT_KEY get_input();


