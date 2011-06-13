#include <stdio.h>
#include <string.h>
#include "libint.h"
#include "hrr_header.h"

extern void vrr_order_gdhg(Libint_t*, prim_data*);

  /* Computes quartets of (gd|hg) integrals */

REALTYPE *hrr_order_gdhg(Libint_t *Libint, int num_prim_comb)
{
 prim_data *Data = Libint->PrimQuartet;
 REALTYPE *int_stack = Libint->int_stack;
 int i;

 Libint->vrr_classes[4][5] = int_stack + 0;
 Libint->vrr_classes[4][6] = int_stack + 315;
 Libint->vrr_classes[4][7] = int_stack + 735;
 Libint->vrr_classes[4][8] = int_stack + 1275;
 Libint->vrr_classes[4][9] = int_stack + 1950;
 Libint->vrr_classes[5][5] = int_stack + 2775;
 Libint->vrr_classes[5][6] = int_stack + 3216;
 Libint->vrr_classes[5][7] = int_stack + 3804;
 Libint->vrr_classes[5][8] = int_stack + 4560;
 Libint->vrr_classes[5][9] = int_stack + 5505;
 Libint->vrr_classes[6][5] = int_stack + 6660;
 Libint->vrr_classes[6][6] = int_stack + 7248;
 Libint->vrr_classes[6][7] = int_stack + 8032;
 Libint->vrr_classes[6][8] = int_stack + 9040;
 Libint->vrr_classes[6][9] = int_stack + 10300;
 memset(int_stack,0,11840*sizeof(REALTYPE));

 Libint->vrr_stack = int_stack + 11840;
 for(i=0;i<num_prim_comb;i++) {
   vrr_order_gdhg(Libint, Data);
   Data++;
 }
 /*--- compute (g0|hp) ---*/
 hrr3_build_hp(Libint->CD,int_stack+11840,int_stack+315,int_stack+0,15);
 /*--- compute (g0|ip) ---*/
 hrr3_build_ip(Libint->CD,int_stack+12785,int_stack+735,int_stack+315,15);
 /*--- compute (g0|hd) ---*/
 hrr3_build_hd(Libint->CD,int_stack+14045,int_stack+12785,int_stack+11840,15);
 /*--- compute (g0|kp) ---*/
 hrr3_build_kp(Libint->CD,int_stack+15935,int_stack+1275,int_stack+735,15);
 /*--- compute (g0|id) ---*/
 hrr3_build_id(Libint->CD,int_stack+17555,int_stack+15935,int_stack+12785,15);
 /*--- compute (g0|hf) ---*/
 hrr3_build_hf(Libint->CD,int_stack+20075,int_stack+17555,int_stack+14045,15);
 /*--- compute (g0|lp) ---*/
 hrr3_build_lp(Libint->CD,int_stack+11840,int_stack+1950,int_stack+1275,15);
 /*--- compute (g0|kd) ---*/
 hrr3_build_kd(Libint->CD,int_stack+23225,int_stack+11840,int_stack+15935,15);
 /*--- compute (g0|if) ---*/
 hrr3_build_if(Libint->CD,int_stack+11840,int_stack+23225,int_stack+17555,15);
 /*--- compute (g0|hg) ---*/
 hrr3_build_hg(Libint->CD,int_stack+23225,int_stack+11840,int_stack+20075,15);
 /*--- compute (h0|hp) ---*/
 hrr3_build_hp(Libint->CD,int_stack+11840,int_stack+3216,int_stack+2775,21);
 /*--- compute (h0|ip) ---*/
 hrr3_build_ip(Libint->CD,int_stack+13163,int_stack+3804,int_stack+3216,21);
 /*--- compute (h0|hd) ---*/
 hrr3_build_hd(Libint->CD,int_stack+14927,int_stack+13163,int_stack+11840,21);
 /*--- compute (h0|kp) ---*/
 hrr3_build_kp(Libint->CD,int_stack+17573,int_stack+4560,int_stack+3804,21);
 /*--- compute (h0|id) ---*/
 hrr3_build_id(Libint->CD,int_stack+0,int_stack+17573,int_stack+13163,21);
 /*--- compute (h0|hf) ---*/
 hrr3_build_hf(Libint->CD,int_stack+27950,int_stack+0,int_stack+14927,21);
 /*--- compute (h0|lp) ---*/
 hrr3_build_lp(Libint->CD,int_stack+11840,int_stack+5505,int_stack+4560,21);
 /*--- compute (h0|kd) ---*/
 hrr3_build_kd(Libint->CD,int_stack+32360,int_stack+11840,int_stack+17573,21);
 /*--- compute (h0|if) ---*/
 hrr3_build_if(Libint->CD,int_stack+11840,int_stack+32360,int_stack+0,21);
 /*--- compute (h0|hg) ---*/
 hrr3_build_hg(Libint->CD,int_stack+0,int_stack+11840,int_stack+27950,21);
 /*--- compute (gp|hg) ---*/
 hrr1_build_gp(Libint->AB,int_stack+27950,int_stack+0,int_stack+23225,315);
 /*--- compute (i0|hp) ---*/
 hrr3_build_hp(Libint->CD,int_stack+11840,int_stack+7248,int_stack+6660,28);
 /*--- compute (i0|ip) ---*/
 hrr3_build_ip(Libint->CD,int_stack+13604,int_stack+8032,int_stack+7248,28);
 /*--- compute (i0|hd) ---*/
 hrr3_build_hd(Libint->CD,int_stack+15956,int_stack+13604,int_stack+11840,28);
 /*--- compute (i0|kp) ---*/
 hrr3_build_kp(Libint->CD,int_stack+19484,int_stack+9040,int_stack+8032,28);
 /*--- compute (i0|id) ---*/
 hrr3_build_id(Libint->CD,int_stack+22508,int_stack+19484,int_stack+13604,28);
 /*--- compute (i0|hf) ---*/
 hrr3_build_hf(Libint->CD,int_stack+42125,int_stack+22508,int_stack+15956,28);
 /*--- compute (i0|lp) ---*/
 hrr3_build_lp(Libint->CD,int_stack+11840,int_stack+10300,int_stack+9040,28);
 /*--- compute (i0|kd) ---*/
 hrr3_build_kd(Libint->CD,int_stack+48005,int_stack+11840,int_stack+19484,28);
 /*--- compute (i0|if) ---*/
 hrr3_build_if(Libint->CD,int_stack+6615,int_stack+48005,int_stack+22508,28);
 /*--- compute (i0|hg) ---*/
 hrr3_build_hg(Libint->CD,int_stack+14455,int_stack+6615,int_stack+42125,28);
 /*--- compute (hp|hg) ---*/
 hrr1_build_hp(Libint->AB,int_stack+42125,int_stack+14455,int_stack+0,315);
 /*--- compute (gd|hg) ---*/
 hrr1_build_gd(Libint->AB,int_stack+61970,int_stack+42125,int_stack+27950,315);
 return int_stack+61970;}