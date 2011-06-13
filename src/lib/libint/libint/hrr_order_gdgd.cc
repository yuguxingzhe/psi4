#include <stdio.h>
#include <string.h>
#include "libint.h"
#include "hrr_header.h"

extern void vrr_order_gdgd(Libint_t*, prim_data*);

  /* Computes quartets of (gd|gd) integrals */

REALTYPE *hrr_order_gdgd(Libint_t *Libint, int num_prim_comb)
{
 prim_data *Data = Libint->PrimQuartet;
 REALTYPE *int_stack = Libint->int_stack;
 int i;

 Libint->vrr_classes[4][4] = int_stack + 0;
 Libint->vrr_classes[4][5] = int_stack + 225;
 Libint->vrr_classes[4][6] = int_stack + 540;
 Libint->vrr_classes[5][4] = int_stack + 960;
 Libint->vrr_classes[5][5] = int_stack + 1275;
 Libint->vrr_classes[5][6] = int_stack + 1716;
 Libint->vrr_classes[6][4] = int_stack + 2304;
 Libint->vrr_classes[6][5] = int_stack + 2724;
 Libint->vrr_classes[6][6] = int_stack + 3312;
 memset(int_stack,0,4096*sizeof(REALTYPE));

 Libint->vrr_stack = int_stack + 4096;
 for(i=0;i<num_prim_comb;i++) {
   vrr_order_gdgd(Libint, Data);
   Data++;
 }
 /*--- compute (g0|gp) ---*/
 hrr3_build_gp(Libint->CD,int_stack+4096,int_stack+225,int_stack+0,15);
 /*--- compute (g0|hp) ---*/
 hrr3_build_hp(Libint->CD,int_stack+4771,int_stack+540,int_stack+225,15);
 /*--- compute (g0|gd) ---*/
 hrr3_build_gd(Libint->CD,int_stack+5716,int_stack+4771,int_stack+4096,15);
 /*--- compute (h0|gp) ---*/
 hrr3_build_gp(Libint->CD,int_stack+4096,int_stack+1275,int_stack+960,21);
 /*--- compute (h0|hp) ---*/
 hrr3_build_hp(Libint->CD,int_stack+7066,int_stack+1716,int_stack+1275,21);
 /*--- compute (h0|gd) ---*/
 hrr3_build_gd(Libint->CD,int_stack+0,int_stack+7066,int_stack+4096,21);
 /*--- compute (gp|gd) ---*/
 hrr1_build_gp(Libint->AB,int_stack+7066,int_stack+0,int_stack+5716,90);
 /*--- compute (i0|gp) ---*/
 hrr3_build_gp(Libint->CD,int_stack+4096,int_stack+2724,int_stack+2304,28);
 /*--- compute (i0|hp) ---*/
 hrr3_build_hp(Libint->CD,int_stack+11116,int_stack+3312,int_stack+2724,28);
 /*--- compute (i0|gd) ---*/
 hrr3_build_gd(Libint->CD,int_stack+12880,int_stack+11116,int_stack+4096,28);
 /*--- compute (hp|gd) ---*/
 hrr1_build_hp(Libint->AB,int_stack+15400,int_stack+12880,int_stack+0,90);
 /*--- compute (gd|gd) ---*/
 hrr1_build_gd(Libint->AB,int_stack+21070,int_stack+15400,int_stack+7066,90);
 return int_stack+21070;}