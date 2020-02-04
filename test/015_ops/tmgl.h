#define SRC_LANGUAGE "positive integer"
#define DST_LANGUAGE "test"

const tword labels[];

// Driving table for the program

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __program  (tword)&start[1]
#define __readint  (tword)&labels[1]
	__readint,
#define __n        (tword)&labels[2]
	__n,
#define __output   (tword)&start[3]
	1 + (tword)&parse,
#define __ops      (tword)&labels[3]
	__ops,
#undef _1
#define _1         (tword)&start[5]
	(tword)&_tp,
	4,
	(tword)&_tp,
	3,
	(tword)&_tp,
	2,
	1 + (tword)&_tp,
	1,
#undef _2
#define _2         (tword)&start[13]
	0,
// __ops:
#define __basic    (tword)&labels[4]
	__basic,
#define __more     (tword)&labels[5]
	__more,
#define __bitw     (tword)&labels[6]
	__bitw,
#define __logic    (tword)&labels[7]
	__logic,
	(tword)&trans,
	1 + _1,
	(tword)&_l,
	__n,
	(tword)&_l,
	_2,
	(tword)&_gt,
	(tword)&_t,
	(tword)&alt,
#define __done     (tword)&labels[8]
	__done,
	(tword)&_l,
	__n,
	(tword)&_l,
	__n,
	(tword)&_ng,
	(tword)&_st,
	(tword)&_p,
	1 + __output,
// __done:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[37]
	(tword)&_tp,
	6,
	(tword)&_tp,
	5,
	(tword)&_tp,
	4,
	(tword)&_tp,
	3,
	(tword)&_tp,
	2,
	1 + (tword)&_tp,
	1,
// __basic:
#define __print    (tword)&labels[9]
	__print,
#define __addop    (tword)&labels[10]
	__addop,
#define __subop    (tword)&labels[11]
	__subop,
#define __mulop    (tword)&labels[12]
	__mulop,
#define __dvrop    (tword)&labels[13]
	__dvrop,
#define __dvqop    (tword)&labels[14]
	__dvqop,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[57]
	(tword)"n=",
#undef _1
#define _1         (tword)&start[58]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
#define _tn        (tword)&labels[15]
	1 + _tn,
// __print:
	(tword)&_l,
#define __i        (tword)&labels[16]
	__i,
	(tword)&_l,
	__n,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[73]
	017115,
#undef _3
#define _3         (tword)&start[74]
	(tword)"n+7757 ",
#undef _2
#define _2         (tword)&start[75]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __addop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_a,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[93]
	013117,
#undef _3
#define _3         (tword)&start[94]
	(tword)"n-5711 ",
#undef _2
#define _2         (tword)&start[95]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __subop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_s,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[113]
	015,
#undef _3
#define _3         (tword)&start[114]
	(tword)"n*13 ",
#undef _2
#define _2         (tword)&start[115]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __mulop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_m,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[133]
	011,
#undef _3
#define _3         (tword)&start[134]
	(tword)"n/9 ",
#undef _2
#define _2         (tword)&start[135]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __dvrop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_q,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[153]
	075,
#undef _3
#define _3         (tword)&start[154]
	(tword)"n%61 ",
#undef _2
#define _2         (tword)&start[155]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __dvqop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_r,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[173]
	(tword)&_tp,
	5,
	(tword)&_tp,
	4,
	(tword)&_tp,
	3,
	(tword)&_tp,
	2,
	1 + (tword)&_tp,
	1,
// __more:
#define __shrop    (tword)&labels[17]
	__shrop,
#define __shlop    (tword)&labels[18]
	__shlop,
#define __comop    (tword)&labels[19]
	__comop,
#define __notop    (tword)&labels[20]
	__notop,
#define __negop    (tword)&labels[21]
	__negop,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[190]
	4,
#undef _3
#define _3         (tword)&start[191]
	(tword)"n<<4 ",
#undef _2
#define _2         (tword)&start[192]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __shrop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_sl,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[210]
	4,
#undef _3
#define _3         (tword)&start[211]
	(tword)">",
#undef _4
#define _4         (tword)&start[212]
	(tword)">4 ",
#undef _2
#define _2         (tword)&start[213]
	(tword)&_txs,
	(tword)'n',
	(tword)&_tx,
	_3,
	(tword)&_tx,
	_4,
	(tword)&_tp,
	1,
	1 + _tn,
// __shlop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_sr,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _2
#define _2         (tword)&start[235]
	(tword)"~n ",
#undef _1
#define _1         (tword)&start[236]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
	1 + _tn,
// __comop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_cm,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[252]
	(tword)"!n ",
#undef _1
#define _1         (tword)&start[253]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
	1 + _tn,
// __notop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_nt,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[269]
	(tword)"-n ",
#undef _1
#define _1         (tword)&start[270]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
	1 + _tn,
// __negop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_ng,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[286]
	(tword)&_tp,
	3,
	(tword)&_tp,
	2,
	1 + (tword)&_tp,
	1,
// __bitw:
#define __andop    (tword)&labels[22]
	__andop,
#define __orop     (tword)&labels[23]
	__orop,
#define __xorop    (tword)&labels[24]
	__xorop,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[297]
	02525,
#undef _3
#define _3         (tword)&start[298]
	(tword)"n&0x555 ",
#undef _2
#define _2         (tword)&start[299]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __andop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_n,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[317]
	02525,
#undef _3
#define _3         (tword)&start[318]
	(tword)"n|0x555 ",
#undef _2
#define _2         (tword)&start[319]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __orop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_o,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[337]
	02525,
#undef _3
#define _3         (tword)&start[338]
	(tword)"n^0x555 ",
#undef _2
#define _2         (tword)&start[339]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __xorop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_x,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[357]
	(tword)&_tp,
	7,
	(tword)&_tp,
	6,
	(tword)&_tp,
	5,
	(tword)&_tp,
	4,
	(tword)&_tp,
	3,
	(tword)&_tp,
	2,
	1 + (tword)&_tp,
	1,
// __logic:
#define __ltop     (tword)&labels[25]
	__ltop,
#define __gtop     (tword)&labels[26]
	__gtop,
#define __leop     (tword)&labels[27]
	__leop,
#define __geop     (tword)&labels[28]
	__geop,
#define __eqop     (tword)&labels[29]
	__eqop,
#define __neop     (tword)&labels[30]
	__neop,
#define __condop   (tword)&labels[31]
	__condop,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[380]
	0400,
#undef _3
#define _3         (tword)&start[381]
	(tword)"n<256 ",
#undef _2
#define _2         (tword)&start[382]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __ltop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_lt,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[400]
	0400,
#undef _3
#define _3         (tword)&start[401]
	(tword)">256 ",
#undef _2
#define _2         (tword)&start[402]
	(tword)&_txs,
	(tword)'n',
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __gtop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_gt,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[422]
	0400,
#undef _3
#define _3         (tword)&start[423]
	(tword)"n<=256 ",
#undef _2
#define _2         (tword)&start[424]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __leop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_le,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[442]
	0400,
#undef _3
#define _3         (tword)&start[443]
	(tword)">=256 ",
#undef _2
#define _2         (tword)&start[444]
	(tword)&_txs,
	(tword)'n',
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __geop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_ge,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _2
#define _2         (tword)&start[464]
	1,
#undef _4
#define _4         (tword)&start[465]
	(tword)"n==1 ",
#undef _3
#define _3         (tword)&start[466]
	(tword)&_tx,
	_4,
	(tword)&_tp,
	1,
	1 + _tn,
// __eqop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_2,
	(tword)&_eq,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _3,
#undef _1
#define _1         (tword)&start[484]
	1,
#undef _3
#define _3         (tword)&start[485]
	(tword)"n!=1 ",
#undef _2
#define _2         (tword)&start[486]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __neop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_ne,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[504]
	3,
#undef _2
#define _2         (tword)&start[505]
	0,
#undef _3
#define _3         (tword)&start[506]
	1,
#undef _5
#define _5         (tword)&start[507]
	(tword)"n&3?0:1 ",
#undef _4
#define _4         (tword)&start[508]
	(tword)&_tx,
	_5,
	(tword)&_tp,
	1,
	1 + _tn,
// __condop:
	(tword)&_l,
	__i,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_n,
	(tword)&_t,
	(tword)&alt,
#define __2        (tword)&labels[32]
	__2,
	(tword)&_l,
	_2,
	(tword)&salt,
#define __3        (tword)&labels[33]
	__3,
// __2:
	(tword)&_l,
	_3,
// __3:
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _4,
#undef _1
#define _1         (tword)&start[535]
	1,
#undef _2
#define _2         (tword)&start[536]
	1,
#undef _3
#define _3         (tword)&start[537]
	0,
#undef _4
#define _4         (tword)&start[538]
	(tword)'\n',
// __readint:
	(tword)&params,
	_1,
	(tword)&push,
	_2,
	__i,
	(tword)&string,
#define __space    (tword)&labels[34]
	__space,
	(tword)&_l,
	(tword)((tuword)-1<<1),
	(tword)&_l,
	_3,
	(tword)&_st,
	(tword)&_p,
#define __inta     (tword)&labels[35]
	__inta,
#define __int1     (tword)&start[553]
	(tword)&_l,
	(tword)((tuword)-1<<1),
	(tword)&_l,
	(tword)((tuword)-1<<1),
	(tword)&_l,
	_4,
	(tword)&_m,
	(tword)&_l,
	__i,
	(tword)&_a,
	(tword)&_st,
	(tword)&_p,
	__inta,
	1 + (tword)&salt,
	__int1,
#undef _1
#define _1         (tword)&start[568]
	072,
#undef _3
#define _3         (tword)&start[569]
	060,
#undef _4
#define _4         (tword)&start[570]
	0,
// __inta:
	(tword)&tchar,
	__i,
	(tword)&_l,
	__i,
	(tword)&_l,
	_1,
	(tword)&_lt,
	(tword)&_t,
	(tword)&_l,
	__i,
	(tword)&_l,
	_3,
	(tword)&_s,
	(tword)&_u,
	(tword)&_l,
	_4,
	(tword)&_ge,
	1 + (tword)&_t,
// __i:
	0,
// __n:
	0,
// __space:
	1,
#define __classtab (tword)&start[592]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	1,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define _pn        (tword)&start[720]
	1 + (tword)&_pxs,
	(tword)'\n',
// _tn:
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[539],     // __readint
	(tword)&start[590],     // __n
	(tword)&start[14],      // __ops
	(tword)&start[49],      // __basic
	(tword)&start[183],     // __more
	(tword)&start[292],     // __bitw
	(tword)&start[371],     // __logic
	(tword)&start[36],      // __done
	(tword)&start[63],      // __print
	(tword)&start[80],      // __addop
	(tword)&start[100],     // __subop
	(tword)&start[120],     // __mulop
	(tword)&start[140],     // __dvrop
	(tword)&start[160],     // __dvqop
	(tword)&start[722],     // _tn
	(tword)&start[589],     // __i
	(tword)&start[197],     // __shrop
	(tword)&start[222],     // __shlop
	(tword)&start[241],     // __comop
	(tword)&start[258],     // __notop
	(tword)&start[275],     // __negop
	(tword)&start[304],     // __andop
	(tword)&start[324],     // __orop
	(tword)&start[344],     // __xorop
	(tword)&start[387],     // __ltop
	(tword)&start[409],     // __gtop
	(tword)&start[429],     // __leop
	(tword)&start[451],     // __geop
	(tword)&start[471],     // __eqop
	(tword)&start[491],     // __neop
	(tword)&start[513],     // __condop
	(tword)&start[527],     // __2
	(tword)&start[529],     // __3
	(tword)&start[591],     // __space
	(tword)&start[571],     // __inta
};

// Used builtins:
//   _a
//   _cm
//   _eq
//   _ge
//   _gt
//   _l
//   _le
//   _lt
//   _m
//   _n
//   _ne
//   _ng
//   _nt
//   _o
//   _p
//   _pxs
//   _q
//   _r
//   _s
//   _sl
//   _sr
//   _st
//   _t
//   _tp
//   _tx
//   _txs
//   _u
//   _x
//   alt
//   decimal
//   params
//   parse
//   push
//   salt
//   string
//   succ
//   tchar
//   trans
