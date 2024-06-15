
bomb:     file format elf64-x86-64


Disassembly of section .init:

0000000000002000 <_init>:
    2000:	f3 0f 1e fa          	endbr64 
    2004:	48 83 ec 08          	sub    $0x8,%rsp
    2008:	48 8b 05 d9 4f 00 00 	mov    0x4fd9(%rip),%rax        # 6fe8 <__gmon_start__@Base>
    200f:	48 85 c0             	test   %rax,%rax
    2012:	74 02                	je     2016 <_init+0x16>
    2014:	ff d0                	call   *%rax
    2016:	48 83 c4 08          	add    $0x8,%rsp
    201a:	c3                   	ret    

Disassembly of section .plt:

0000000000002020 <.plt>:
    2020:	ff 35 ba 4e 00 00    	push   0x4eba(%rip)        # 6ee0 <_GLOBAL_OFFSET_TABLE_+0x8>
    2026:	f2 ff 25 bb 4e 00 00 	bnd jmp *0x4ebb(%rip)        # 6ee8 <_GLOBAL_OFFSET_TABLE_+0x10>
    202d:	0f 1f 00             	nopl   (%rax)
    2030:	f3 0f 1e fa          	endbr64 
    2034:	68 00 00 00 00       	push   $0x0
    2039:	f2 e9 e1 ff ff ff    	bnd jmp 2020 <_init+0x20>
    203f:	90                   	nop
    2040:	f3 0f 1e fa          	endbr64 
    2044:	68 01 00 00 00       	push   $0x1
    2049:	f2 e9 d1 ff ff ff    	bnd jmp 2020 <_init+0x20>
    204f:	90                   	nop
    2050:	f3 0f 1e fa          	endbr64 
    2054:	68 02 00 00 00       	push   $0x2
    2059:	f2 e9 c1 ff ff ff    	bnd jmp 2020 <_init+0x20>
    205f:	90                   	nop
    2060:	f3 0f 1e fa          	endbr64 
    2064:	68 03 00 00 00       	push   $0x3
    2069:	f2 e9 b1 ff ff ff    	bnd jmp 2020 <_init+0x20>
    206f:	90                   	nop
    2070:	f3 0f 1e fa          	endbr64 
    2074:	68 04 00 00 00       	push   $0x4
    2079:	f2 e9 a1 ff ff ff    	bnd jmp 2020 <_init+0x20>
    207f:	90                   	nop
    2080:	f3 0f 1e fa          	endbr64 
    2084:	68 05 00 00 00       	push   $0x5
    2089:	f2 e9 91 ff ff ff    	bnd jmp 2020 <_init+0x20>
    208f:	90                   	nop
    2090:	f3 0f 1e fa          	endbr64 
    2094:	68 06 00 00 00       	push   $0x6
    2099:	f2 e9 81 ff ff ff    	bnd jmp 2020 <_init+0x20>
    209f:	90                   	nop
    20a0:	f3 0f 1e fa          	endbr64 
    20a4:	68 07 00 00 00       	push   $0x7
    20a9:	f2 e9 71 ff ff ff    	bnd jmp 2020 <_init+0x20>
    20af:	90                   	nop
    20b0:	f3 0f 1e fa          	endbr64 
    20b4:	68 08 00 00 00       	push   $0x8
    20b9:	f2 e9 61 ff ff ff    	bnd jmp 2020 <_init+0x20>
    20bf:	90                   	nop
    20c0:	f3 0f 1e fa          	endbr64 
    20c4:	68 09 00 00 00       	push   $0x9
    20c9:	f2 e9 51 ff ff ff    	bnd jmp 2020 <_init+0x20>
    20cf:	90                   	nop
    20d0:	f3 0f 1e fa          	endbr64 
    20d4:	68 0a 00 00 00       	push   $0xa
    20d9:	f2 e9 41 ff ff ff    	bnd jmp 2020 <_init+0x20>
    20df:	90                   	nop
    20e0:	f3 0f 1e fa          	endbr64 
    20e4:	68 0b 00 00 00       	push   $0xb
    20e9:	f2 e9 31 ff ff ff    	bnd jmp 2020 <_init+0x20>
    20ef:	90                   	nop
    20f0:	f3 0f 1e fa          	endbr64 
    20f4:	68 0c 00 00 00       	push   $0xc
    20f9:	f2 e9 21 ff ff ff    	bnd jmp 2020 <_init+0x20>
    20ff:	90                   	nop
    2100:	f3 0f 1e fa          	endbr64 
    2104:	68 0d 00 00 00       	push   $0xd
    2109:	f2 e9 11 ff ff ff    	bnd jmp 2020 <_init+0x20>
    210f:	90                   	nop
    2110:	f3 0f 1e fa          	endbr64 
    2114:	68 0e 00 00 00       	push   $0xe
    2119:	f2 e9 01 ff ff ff    	bnd jmp 2020 <_init+0x20>
    211f:	90                   	nop
    2120:	f3 0f 1e fa          	endbr64 
    2124:	68 0f 00 00 00       	push   $0xf
    2129:	f2 e9 f1 fe ff ff    	bnd jmp 2020 <_init+0x20>
    212f:	90                   	nop
    2130:	f3 0f 1e fa          	endbr64 
    2134:	68 10 00 00 00       	push   $0x10
    2139:	f2 e9 e1 fe ff ff    	bnd jmp 2020 <_init+0x20>
    213f:	90                   	nop
    2140:	f3 0f 1e fa          	endbr64 
    2144:	68 11 00 00 00       	push   $0x11
    2149:	f2 e9 d1 fe ff ff    	bnd jmp 2020 <_init+0x20>
    214f:	90                   	nop
    2150:	f3 0f 1e fa          	endbr64 
    2154:	68 12 00 00 00       	push   $0x12
    2159:	f2 e9 c1 fe ff ff    	bnd jmp 2020 <_init+0x20>
    215f:	90                   	nop
    2160:	f3 0f 1e fa          	endbr64 
    2164:	68 13 00 00 00       	push   $0x13
    2169:	f2 e9 b1 fe ff ff    	bnd jmp 2020 <_init+0x20>
    216f:	90                   	nop
    2170:	f3 0f 1e fa          	endbr64 
    2174:	68 14 00 00 00       	push   $0x14
    2179:	f2 e9 a1 fe ff ff    	bnd jmp 2020 <_init+0x20>
    217f:	90                   	nop
    2180:	f3 0f 1e fa          	endbr64 
    2184:	68 15 00 00 00       	push   $0x15
    2189:	f2 e9 91 fe ff ff    	bnd jmp 2020 <_init+0x20>
    218f:	90                   	nop
    2190:	f3 0f 1e fa          	endbr64 
    2194:	68 16 00 00 00       	push   $0x16
    2199:	f2 e9 81 fe ff ff    	bnd jmp 2020 <_init+0x20>
    219f:	90                   	nop
    21a0:	f3 0f 1e fa          	endbr64 
    21a4:	68 17 00 00 00       	push   $0x17
    21a9:	f2 e9 71 fe ff ff    	bnd jmp 2020 <_init+0x20>
    21af:	90                   	nop
    21b0:	f3 0f 1e fa          	endbr64 
    21b4:	68 18 00 00 00       	push   $0x18
    21b9:	f2 e9 61 fe ff ff    	bnd jmp 2020 <_init+0x20>
    21bf:	90                   	nop
    21c0:	f3 0f 1e fa          	endbr64 
    21c4:	68 19 00 00 00       	push   $0x19
    21c9:	f2 e9 51 fe ff ff    	bnd jmp 2020 <_init+0x20>
    21cf:	90                   	nop
    21d0:	f3 0f 1e fa          	endbr64 
    21d4:	68 1a 00 00 00       	push   $0x1a
    21d9:	f2 e9 41 fe ff ff    	bnd jmp 2020 <_init+0x20>
    21df:	90                   	nop
    21e0:	f3 0f 1e fa          	endbr64 
    21e4:	68 1b 00 00 00       	push   $0x1b
    21e9:	f2 e9 31 fe ff ff    	bnd jmp 2020 <_init+0x20>
    21ef:	90                   	nop
    21f0:	f3 0f 1e fa          	endbr64 
    21f4:	68 1c 00 00 00       	push   $0x1c
    21f9:	f2 e9 21 fe ff ff    	bnd jmp 2020 <_init+0x20>
    21ff:	90                   	nop

Disassembly of section .plt.got:

0000000000002200 <__cxa_finalize@plt>:
    2200:	f3 0f 1e fa          	endbr64 
    2204:	f2 ff 25 ed 4d 00 00 	bnd jmp *0x4ded(%rip)        # 6ff8 <__cxa_finalize@GLIBC_2.2.5>
    220b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000002210 <getenv@plt>:
    2210:	f3 0f 1e fa          	endbr64 
    2214:	f2 ff 25 d5 4c 00 00 	bnd jmp *0x4cd5(%rip)        # 6ef0 <getenv@GLIBC_2.2.5>
    221b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002220 <strcasecmp@plt>:
    2220:	f3 0f 1e fa          	endbr64 
    2224:	f2 ff 25 cd 4c 00 00 	bnd jmp *0x4ccd(%rip)        # 6ef8 <strcasecmp@GLIBC_2.2.5>
    222b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002230 <__errno_location@plt>:
    2230:	f3 0f 1e fa          	endbr64 
    2234:	f2 ff 25 c5 4c 00 00 	bnd jmp *0x4cc5(%rip)        # 6f00 <__errno_location@GLIBC_2.2.5>
    223b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002240 <strcpy@plt>:
    2240:	f3 0f 1e fa          	endbr64 
    2244:	f2 ff 25 bd 4c 00 00 	bnd jmp *0x4cbd(%rip)        # 6f08 <strcpy@GLIBC_2.2.5>
    224b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002250 <puts@plt>:
    2250:	f3 0f 1e fa          	endbr64 
    2254:	f2 ff 25 b5 4c 00 00 	bnd jmp *0x4cb5(%rip)        # 6f10 <puts@GLIBC_2.2.5>
    225b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002260 <write@plt>:
    2260:	f3 0f 1e fa          	endbr64 
    2264:	f2 ff 25 ad 4c 00 00 	bnd jmp *0x4cad(%rip)        # 6f18 <write@GLIBC_2.2.5>
    226b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002270 <strlen@plt>:
    2270:	f3 0f 1e fa          	endbr64 
    2274:	f2 ff 25 a5 4c 00 00 	bnd jmp *0x4ca5(%rip)        # 6f20 <strlen@GLIBC_2.2.5>
    227b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002280 <__stack_chk_fail@plt>:
    2280:	f3 0f 1e fa          	endbr64 
    2284:	f2 ff 25 9d 4c 00 00 	bnd jmp *0x4c9d(%rip)        # 6f28 <__stack_chk_fail@GLIBC_2.4>
    228b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002290 <alarm@plt>:
    2290:	f3 0f 1e fa          	endbr64 
    2294:	f2 ff 25 95 4c 00 00 	bnd jmp *0x4c95(%rip)        # 6f30 <alarm@GLIBC_2.2.5>
    229b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000022a0 <close@plt>:
    22a0:	f3 0f 1e fa          	endbr64 
    22a4:	f2 ff 25 8d 4c 00 00 	bnd jmp *0x4c8d(%rip)        # 6f38 <close@GLIBC_2.2.5>
    22ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000022b0 <read@plt>:
    22b0:	f3 0f 1e fa          	endbr64 
    22b4:	f2 ff 25 85 4c 00 00 	bnd jmp *0x4c85(%rip)        # 6f40 <read@GLIBC_2.2.5>
    22bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000022c0 <fgets@plt>:
    22c0:	f3 0f 1e fa          	endbr64 
    22c4:	f2 ff 25 7d 4c 00 00 	bnd jmp *0x4c7d(%rip)        # 6f48 <fgets@GLIBC_2.2.5>
    22cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000022d0 <strcmp@plt>:
    22d0:	f3 0f 1e fa          	endbr64 
    22d4:	f2 ff 25 75 4c 00 00 	bnd jmp *0x4c75(%rip)        # 6f50 <strcmp@GLIBC_2.2.5>
    22db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000022e0 <signal@plt>:
    22e0:	f3 0f 1e fa          	endbr64 
    22e4:	f2 ff 25 6d 4c 00 00 	bnd jmp *0x4c6d(%rip)        # 6f58 <signal@GLIBC_2.2.5>
    22eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000022f0 <gethostbyname@plt>:
    22f0:	f3 0f 1e fa          	endbr64 
    22f4:	f2 ff 25 65 4c 00 00 	bnd jmp *0x4c65(%rip)        # 6f60 <gethostbyname@GLIBC_2.2.5>
    22fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002300 <__memmove_chk@plt>:
    2300:	f3 0f 1e fa          	endbr64 
    2304:	f2 ff 25 5d 4c 00 00 	bnd jmp *0x4c5d(%rip)        # 6f68 <__memmove_chk@GLIBC_2.3.4>
    230b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002310 <strtol@plt>:
    2310:	f3 0f 1e fa          	endbr64 
    2314:	f2 ff 25 55 4c 00 00 	bnd jmp *0x4c55(%rip)        # 6f70 <strtol@GLIBC_2.2.5>
    231b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002320 <fflush@plt>:
    2320:	f3 0f 1e fa          	endbr64 
    2324:	f2 ff 25 4d 4c 00 00 	bnd jmp *0x4c4d(%rip)        # 6f78 <fflush@GLIBC_2.2.5>
    232b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002330 <__isoc99_sscanf@plt>:
    2330:	f3 0f 1e fa          	endbr64 
    2334:	f2 ff 25 45 4c 00 00 	bnd jmp *0x4c45(%rip)        # 6f80 <__isoc99_sscanf@GLIBC_2.7>
    233b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002340 <__printf_chk@plt>:
    2340:	f3 0f 1e fa          	endbr64 
    2344:	f2 ff 25 3d 4c 00 00 	bnd jmp *0x4c3d(%rip)        # 6f88 <__printf_chk@GLIBC_2.3.4>
    234b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002350 <fopen@plt>:
    2350:	f3 0f 1e fa          	endbr64 
    2354:	f2 ff 25 35 4c 00 00 	bnd jmp *0x4c35(%rip)        # 6f90 <fopen@GLIBC_2.2.5>
    235b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002360 <gethostname@plt>:
    2360:	f3 0f 1e fa          	endbr64 
    2364:	f2 ff 25 2d 4c 00 00 	bnd jmp *0x4c2d(%rip)        # 6f98 <gethostname@GLIBC_2.2.5>
    236b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002370 <exit@plt>:
    2370:	f3 0f 1e fa          	endbr64 
    2374:	f2 ff 25 25 4c 00 00 	bnd jmp *0x4c25(%rip)        # 6fa0 <exit@GLIBC_2.2.5>
    237b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002380 <connect@plt>:
    2380:	f3 0f 1e fa          	endbr64 
    2384:	f2 ff 25 1d 4c 00 00 	bnd jmp *0x4c1d(%rip)        # 6fa8 <connect@GLIBC_2.2.5>
    238b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002390 <__fprintf_chk@plt>:
    2390:	f3 0f 1e fa          	endbr64 
    2394:	f2 ff 25 15 4c 00 00 	bnd jmp *0x4c15(%rip)        # 6fb0 <__fprintf_chk@GLIBC_2.3.4>
    239b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000023a0 <sleep@plt>:
    23a0:	f3 0f 1e fa          	endbr64 
    23a4:	f2 ff 25 0d 4c 00 00 	bnd jmp *0x4c0d(%rip)        # 6fb8 <sleep@GLIBC_2.2.5>
    23ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000023b0 <__ctype_b_loc@plt>:
    23b0:	f3 0f 1e fa          	endbr64 
    23b4:	f2 ff 25 05 4c 00 00 	bnd jmp *0x4c05(%rip)        # 6fc0 <__ctype_b_loc@GLIBC_2.3>
    23bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000023c0 <__sprintf_chk@plt>:
    23c0:	f3 0f 1e fa          	endbr64 
    23c4:	f2 ff 25 fd 4b 00 00 	bnd jmp *0x4bfd(%rip)        # 6fc8 <__sprintf_chk@GLIBC_2.3.4>
    23cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000023d0 <socket@plt>:
    23d0:	f3 0f 1e fa          	endbr64 
    23d4:	f2 ff 25 f5 4b 00 00 	bnd jmp *0x4bf5(%rip)        # 6fd0 <socket@GLIBC_2.2.5>
    23db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000023e0 <_start>:
    23e0:	f3 0f 1e fa          	endbr64 
    23e4:	31 ed                	xor    %ebp,%ebp
    23e6:	49 89 d1             	mov    %rdx,%r9
    23e9:	5e                   	pop    %rsi
    23ea:	48 89 e2             	mov    %rsp,%rdx
    23ed:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    23f1:	50                   	push   %rax
    23f2:	54                   	push   %rsp
    23f3:	45 31 c0             	xor    %r8d,%r8d
    23f6:	31 c9                	xor    %ecx,%ecx
    23f8:	48 8d 3d ca 00 00 00 	lea    0xca(%rip),%rdi        # 24c9 <main>
    23ff:	ff 15 d3 4b 00 00    	call   *0x4bd3(%rip)        # 6fd8 <__libc_start_main@GLIBC_2.34>
    2405:	f4                   	hlt    
    2406:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    240d:	00 00 00 

0000000000002410 <deregister_tm_clones>:
    2410:	48 8d 3d 39 56 00 00 	lea    0x5639(%rip),%rdi        # 7a50 <__TMC_END__>
    2417:	48 8d 05 32 56 00 00 	lea    0x5632(%rip),%rax        # 7a50 <__TMC_END__>
    241e:	48 39 f8             	cmp    %rdi,%rax
    2421:	74 15                	je     2438 <deregister_tm_clones+0x28>
    2423:	48 8b 05 b6 4b 00 00 	mov    0x4bb6(%rip),%rax        # 6fe0 <_ITM_deregisterTMCloneTable@Base>
    242a:	48 85 c0             	test   %rax,%rax
    242d:	74 09                	je     2438 <deregister_tm_clones+0x28>
    242f:	ff e0                	jmp    *%rax
    2431:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    2438:	c3                   	ret    
    2439:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000002440 <register_tm_clones>:
    2440:	48 8d 3d 09 56 00 00 	lea    0x5609(%rip),%rdi        # 7a50 <__TMC_END__>
    2447:	48 8d 35 02 56 00 00 	lea    0x5602(%rip),%rsi        # 7a50 <__TMC_END__>
    244e:	48 29 fe             	sub    %rdi,%rsi
    2451:	48 89 f0             	mov    %rsi,%rax
    2454:	48 c1 ee 3f          	shr    $0x3f,%rsi
    2458:	48 c1 f8 03          	sar    $0x3,%rax
    245c:	48 01 c6             	add    %rax,%rsi
    245f:	48 d1 fe             	sar    %rsi
    2462:	74 14                	je     2478 <register_tm_clones+0x38>
    2464:	48 8b 05 85 4b 00 00 	mov    0x4b85(%rip),%rax        # 6ff0 <_ITM_registerTMCloneTable@Base>
    246b:	48 85 c0             	test   %rax,%rax
    246e:	74 08                	je     2478 <register_tm_clones+0x38>
    2470:	ff e0                	jmp    *%rax
    2472:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    2478:	c3                   	ret    
    2479:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000002480 <__do_global_dtors_aux>:
    2480:	f3 0f 1e fa          	endbr64 
    2484:	80 3d fd 55 00 00 00 	cmpb   $0x0,0x55fd(%rip)        # 7a88 <completed.0>
    248b:	75 2b                	jne    24b8 <__do_global_dtors_aux+0x38>
    248d:	55                   	push   %rbp
    248e:	48 83 3d 62 4b 00 00 	cmpq   $0x0,0x4b62(%rip)        # 6ff8 <__cxa_finalize@GLIBC_2.2.5>
    2495:	00 
    2496:	48 89 e5             	mov    %rsp,%rbp
    2499:	74 0c                	je     24a7 <__do_global_dtors_aux+0x27>
    249b:	48 8b 3d 66 4b 00 00 	mov    0x4b66(%rip),%rdi        # 7008 <__dso_handle>
    24a2:	e8 59 fd ff ff       	call   2200 <__cxa_finalize@plt>
    24a7:	e8 64 ff ff ff       	call   2410 <deregister_tm_clones>
    24ac:	c6 05 d5 55 00 00 01 	movb   $0x1,0x55d5(%rip)        # 7a88 <completed.0>
    24b3:	5d                   	pop    %rbp
    24b4:	c3                   	ret    
    24b5:	0f 1f 00             	nopl   (%rax)
    24b8:	c3                   	ret    
    24b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000024c0 <frame_dummy>:
    24c0:	f3 0f 1e fa          	endbr64 
    24c4:	e9 77 ff ff ff       	jmp    2440 <register_tm_clones>

00000000000024c9 <main>:
    24c9:	f3 0f 1e fa          	endbr64 
    24cd:	53                   	push   %rbx
    24ce:	83 ff 01             	cmp    $0x1,%edi
    24d1:	0f 84 f8 00 00 00    	je     25cf <main+0x106>
    24d7:	48 89 f3             	mov    %rsi,%rbx
    24da:	83 ff 02             	cmp    $0x2,%edi
    24dd:	0f 85 21 01 00 00    	jne    2604 <main+0x13b>
    24e3:	48 8b 7e 08          	mov    0x8(%rsi),%rdi
    24e7:	48 8d 35 b5 2c 00 00 	lea    0x2cb5(%rip),%rsi        # 51a3 <array.0+0x1003>
    24ee:	e8 5d fe ff ff       	call   2350 <fopen@plt>
    24f3:	48 89 05 96 55 00 00 	mov    %rax,0x5596(%rip)        # 7a90 <infile>
    24fa:	48 85 c0             	test   %rax,%rax
    24fd:	0f 84 df 00 00 00    	je     25e2 <main+0x119>
    2503:	e8 d5 09 00 00       	call   2edd <initialize_bomb>
    2508:	48 8d 3d 79 1b 00 00 	lea    0x1b79(%rip),%rdi        # 4088 <_IO_stdin_used+0x88>
    250f:	e8 3c fd ff ff       	call   2250 <puts@plt>
    2514:	48 8d 3d ad 1b 00 00 	lea    0x1bad(%rip),%rdi        # 40c8 <_IO_stdin_used+0xc8>
    251b:	e8 30 fd ff ff       	call   2250 <puts@plt>
    2520:	e8 d1 0c 00 00       	call   31f6 <read_line>
    2525:	48 89 c7             	mov    %rax,%rdi
    2528:	e8 fa 00 00 00       	call   2627 <phase_1>
    252d:	e8 fe 0d 00 00       	call   3330 <phase_defused>
    2532:	48 8d 3d bf 1b 00 00 	lea    0x1bbf(%rip),%rdi        # 40f8 <_IO_stdin_used+0xf8>
    2539:	e8 12 fd ff ff       	call   2250 <puts@plt>
    253e:	e8 b3 0c 00 00       	call   31f6 <read_line>
    2543:	48 89 c7             	mov    %rax,%rdi
    2546:	e8 bc 01 00 00       	call   2707 <phase_2>
    254b:	e8 e0 0d 00 00       	call   3330 <phase_defused>
    2550:	48 8d 3d e4 1a 00 00 	lea    0x1ae4(%rip),%rdi        # 403b <_IO_stdin_used+0x3b>
    2557:	e8 f4 fc ff ff       	call   2250 <puts@plt>
    255c:	e8 95 0c 00 00       	call   31f6 <read_line>
    2561:	48 89 c7             	mov    %rax,%rdi
    2564:	e8 15 02 00 00       	call   277e <phase_3>
    2569:	e8 c2 0d 00 00       	call   3330 <phase_defused>
    256e:	48 8d 3d e4 1a 00 00 	lea    0x1ae4(%rip),%rdi        # 4059 <_IO_stdin_used+0x59>
    2575:	e8 d6 fc ff ff       	call   2250 <puts@plt>
    257a:	e8 77 0c 00 00       	call   31f6 <read_line>
    257f:	48 89 c7             	mov    %rax,%rdi
    2582:	e8 0b 03 00 00       	call   2892 <phase_4>
    2587:	e8 a4 0d 00 00       	call   3330 <phase_defused>
    258c:	48 8d 3d 95 1b 00 00 	lea    0x1b95(%rip),%rdi        # 4128 <_IO_stdin_used+0x128>
    2593:	e8 b8 fc ff ff       	call   2250 <puts@plt>
    2598:	e8 59 0c 00 00       	call   31f6 <read_line>
    259d:	48 89 c7             	mov    %rax,%rdi
    25a0:	e8 64 03 00 00       	call   2909 <phase_5>
    25a5:	e8 86 0d 00 00       	call   3330 <phase_defused>
    25aa:	48 8d 3d b7 1a 00 00 	lea    0x1ab7(%rip),%rdi        # 4068 <_IO_stdin_used+0x68>
    25b1:	e8 9a fc ff ff       	call   2250 <puts@plt>
    25b6:	e8 3b 0c 00 00       	call   31f6 <read_line>
    25bb:	48 89 c7             	mov    %rax,%rdi
    25be:	e8 ee 03 00 00       	call   29b1 <phase_6>
    25c3:	e8 68 0d 00 00       	call   3330 <phase_defused>
    25c8:	b8 00 00 00 00       	mov    $0x0,%eax
    25cd:	5b                   	pop    %rbx
    25ce:	c3                   	ret    
    25cf:	48 8b 05 9a 54 00 00 	mov    0x549a(%rip),%rax        # 7a70 <stdin@GLIBC_2.2.5>
    25d6:	48 89 05 b3 54 00 00 	mov    %rax,0x54b3(%rip)        # 7a90 <infile>
    25dd:	e9 21 ff ff ff       	jmp    2503 <main+0x3a>
    25e2:	48 8b 4b 08          	mov    0x8(%rbx),%rcx
    25e6:	48 8b 13             	mov    (%rbx),%rdx
    25e9:	48 8d 35 14 1a 00 00 	lea    0x1a14(%rip),%rsi        # 4004 <_IO_stdin_used+0x4>
    25f0:	bf 01 00 00 00       	mov    $0x1,%edi
    25f5:	e8 46 fd ff ff       	call   2340 <__printf_chk@plt>
    25fa:	bf 08 00 00 00       	mov    $0x8,%edi
    25ff:	e8 6c fd ff ff       	call   2370 <exit@plt>
    2604:	48 8b 16             	mov    (%rsi),%rdx
    2607:	48 8d 35 13 1a 00 00 	lea    0x1a13(%rip),%rsi        # 4021 <_IO_stdin_used+0x21>
    260e:	bf 01 00 00 00       	mov    $0x1,%edi
    2613:	b8 00 00 00 00       	mov    $0x0,%eax
    2618:	e8 23 fd ff ff       	call   2340 <__printf_chk@plt>
    261d:	bf 08 00 00 00       	mov    $0x8,%edi
    2622:	e8 49 fd ff ff       	call   2370 <exit@plt>

0000000000002627 <phase_1>:
    2627:	f3 0f 1e fa          	endbr64 
    262b:	55                   	push   %rbp
    262c:	53                   	push   %rbx
    262d:	48 83 ec 78          	sub    $0x78,%rsp
    2631:	48 89 fb             	mov    %rdi,%rbx
    2634:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    263b:	00 00 
    263d:	48 89 44 24 68       	mov    %rax,0x68(%rsp)
    2642:	31 c0                	xor    %eax,%eax
    2644:	48 b8 43 6f 72 72 65 	movabs $0x2074636572726f43,%rax
    264b:	63 74 20 
    264e:	48 ba 74 65 78 74 20 	movabs $0x2073692074786574,%rdx
    2655:	69 73 20 
    2658:	48 89 04 24          	mov    %rax,(%rsp)
    265c:	48 89 54 24 08       	mov    %rdx,0x8(%rsp)
    2661:	48 c7 44 24 10 00 00 	movq   $0x0,0x10(%rsp)
    2668:	00 00 
    266a:	48 c7 44 24 18 00 00 	movq   $0x0,0x18(%rsp)
    2671:	00 00 
    2673:	48 c7 44 24 20 00 00 	movq   $0x0,0x20(%rsp)
    267a:	00 00 
    267c:	48 c7 44 24 28 00 00 	movq   $0x0,0x28(%rsp)
    2683:	00 00 
    2685:	48 c7 44 24 30 00 00 	movq   $0x0,0x30(%rsp)
    268c:	00 00 
    268e:	48 c7 44 24 38 00 00 	movq   $0x0,0x38(%rsp)
    2695:	00 00 
    2697:	48 c7 44 24 40 00 00 	movq   $0x0,0x40(%rsp)
    269e:	00 00 
    26a0:	48 c7 44 24 48 00 00 	movq   $0x0,0x48(%rsp)
    26a7:	00 00 
    26a9:	48 c7 44 24 50 00 00 	movq   $0x0,0x50(%rsp)
    26b0:	00 00 
    26b2:	48 c7 44 24 58 00 00 	movq   $0x0,0x58(%rsp)
    26b9:	00 00 
    26bb:	c7 44 24 60 00 00 00 	movl   $0x0,0x60(%rsp)
    26c2:	00 
    26c3:	48 89 e5             	mov    %rsp,%rbp
    26c6:	48 8d 35 7f 1a 00 00 	lea    0x1a7f(%rip),%rsi        # 414c <_IO_stdin_used+0x14c>
    26cd:	48 89 ef             	mov    %rbp,%rdi
    26d0:	e8 a3 06 00 00       	call   2d78 <strings_cat>
    26d5:	48 89 ee             	mov    %rbp,%rsi
    26d8:	48 89 df             	mov    %rbx,%rdi
    26db:	e8 38 06 00 00       	call   2d18 <strings_not_equal>
    26e0:	85 c0                	test   %eax,%eax
    26e2:	75 17                	jne    26fb <phase_1+0xd4>
    26e4:	48 8b 44 24 68       	mov    0x68(%rsp),%rax
    26e9:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    26f0:	00 00 
    26f2:	75 0e                	jne    2702 <phase_1+0xdb>
    26f4:	48 83 c4 78          	add    $0x78,%rsp
    26f8:	5b                   	pop    %rbx
    26f9:	5d                   	pop    %rbp
    26fa:	c3                   	ret    
    26fb:	e8 6f 0a 00 00       	call   316f <explode_bomb>
    2700:	eb e2                	jmp    26e4 <phase_1+0xbd>
    2702:	e8 79 fb ff ff       	call   2280 <__stack_chk_fail@plt>

0000000000002707 <phase_2>:
    2707:	f3 0f 1e fa          	endbr64 
    270b:	55                   	push   %rbp
    270c:	53                   	push   %rbx
    270d:	48 83 ec 28          	sub    $0x28,%rsp
    2711:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    2718:	00 00 
    271a:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    271f:	31 c0                	xor    %eax,%eax
    2721:	48 89 e6             	mov    %rsp,%rsi
    2724:	e8 88 0a 00 00       	call   31b1 <read_six_numbers>
    2729:	8b 04 24             	mov    (%rsp),%eax
    272c:	0b 44 24 04          	or     0x4(%rsp),%eax
    2730:	78 0a                	js     273c <phase_2+0x35>
    2732:	48 89 e3             	mov    %rsp,%rbx
    2735:	bd 04 00 00 00       	mov    $0x4,%ebp
    273a:	eb 13                	jmp    274f <phase_2+0x48>
    273c:	e8 2e 0a 00 00       	call   316f <explode_bomb>
    2741:	eb ef                	jmp    2732 <phase_2+0x2b>
    2743:	48 83 c3 04          	add    $0x4,%rbx
    2747:	83 c5 02             	add    $0x2,%ebp
    274a:	83 fd 0c             	cmp    $0xc,%ebp
    274d:	74 13                	je     2762 <phase_2+0x5b>
    274f:	8b 43 04             	mov    0x4(%rbx),%eax
    2752:	03 03                	add    (%rbx),%eax
    2754:	01 e8                	add    %ebp,%eax
    2756:	39 43 08             	cmp    %eax,0x8(%rbx)
    2759:	74 e8                	je     2743 <phase_2+0x3c>
    275b:	e8 0f 0a 00 00       	call   316f <explode_bomb>
    2760:	eb e1                	jmp    2743 <phase_2+0x3c>
    2762:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
    2767:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    276e:	00 00 
    2770:	75 07                	jne    2779 <phase_2+0x72>
    2772:	48 83 c4 28          	add    $0x28,%rsp
    2776:	5b                   	pop    %rbx
    2777:	5d                   	pop    %rbp
    2778:	c3                   	ret    
    2779:	e8 02 fb ff ff       	call   2280 <__stack_chk_fail@plt>

000000000000277e <phase_3>:
    277e:	f3 0f 1e fa          	endbr64 
    2782:	48 83 ec 28          	sub    $0x28,%rsp
    2786:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    278d:	00 00 
    278f:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    2794:	31 c0                	xor    %eax,%eax
    2796:	48 8d 4c 24 10       	lea    0x10(%rsp),%rcx
    279b:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
    27a0:	4c 8d 44 24 14       	lea    0x14(%rsp),%r8
    27a5:	48 8d 35 7e 25 00 00 	lea    0x257e(%rip),%rsi        # 4d2a <array.0+0xb8a>
    27ac:	e8 7f fb ff ff       	call   2330 <__isoc99_sscanf@plt>
    27b1:	83 f8 02             	cmp    $0x2,%eax
    27b4:	7e 1c                	jle    27d2 <phase_3+0x54>
    27b6:	83 7c 24 0c 07       	cmpl   $0x7,0xc(%rsp)
    27bb:	77 71                	ja     282e <phase_3+0xb0>
    27bd:	8b 44 24 0c          	mov    0xc(%rsp),%eax
    27c1:	48 8d 15 b8 19 00 00 	lea    0x19b8(%rip),%rdx        # 4180 <_IO_stdin_used+0x180>
    27c8:	48 63 04 82          	movslq (%rdx,%rax,4),%rax
    27cc:	48 01 d0             	add    %rdx,%rax
    27cf:	3e ff e0             	notrack jmp *%rax
    27d2:	e8 98 09 00 00       	call   316f <explode_bomb>
    27d7:	eb dd                	jmp    27b6 <phase_3+0x38>
    27d9:	bf 64 02 00 00       	mov    $0x264,%edi
    27de:	8b 54 24 14          	mov    0x14(%rsp),%edx
    27e2:	8b 74 24 10          	mov    0x10(%rsp),%esi
    27e6:	e8 c7 04 00 00       	call   2cb2 <check_power_equal>
    27eb:	85 c0                	test   %eax,%eax
    27ed:	74 52                	je     2841 <phase_3+0xc3>
    27ef:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
    27f4:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    27fb:	00 00 
    27fd:	75 49                	jne    2848 <phase_3+0xca>
    27ff:	48 83 c4 28          	add    $0x28,%rsp
    2803:	c3                   	ret    
    2804:	bf f5 00 00 00       	mov    $0xf5,%edi
    2809:	eb d3                	jmp    27de <phase_3+0x60>
    280b:	bf 04 02 00 00       	mov    $0x204,%edi
    2810:	eb cc                	jmp    27de <phase_3+0x60>
    2812:	bf 68 00 00 00       	mov    $0x68,%edi
    2817:	eb c5                	jmp    27de <phase_3+0x60>
    2819:	bf c3 01 00 00       	mov    $0x1c3,%edi
    281e:	eb be                	jmp    27de <phase_3+0x60>
    2820:	bf a4 00 00 00       	mov    $0xa4,%edi
    2825:	eb b7                	jmp    27de <phase_3+0x60>
    2827:	bf dc 03 00 00       	mov    $0x3dc,%edi
    282c:	eb b0                	jmp    27de <phase_3+0x60>
    282e:	e8 3c 09 00 00       	call   316f <explode_bomb>
    2833:	bf 00 00 00 00       	mov    $0x0,%edi
    2838:	eb a4                	jmp    27de <phase_3+0x60>
    283a:	bf 2c 03 00 00       	mov    $0x32c,%edi
    283f:	eb 9d                	jmp    27de <phase_3+0x60>
    2841:	e8 29 09 00 00       	call   316f <explode_bomb>
    2846:	eb a7                	jmp    27ef <phase_3+0x71>
    2848:	e8 33 fa ff ff       	call   2280 <__stack_chk_fail@plt>

000000000000284d <func4>:
    284d:	f3 0f 1e fa          	endbr64 
    2851:	b8 01 00 00 00       	mov    $0x1,%eax
    2856:	85 f6                	test   %esi,%esi
    2858:	74 37                	je     2891 <func4+0x44>
    285a:	53                   	push   %rbx
    285b:	89 fb                	mov    %edi,%ebx
    285d:	40 f6 c6 01          	test   $0x1,%sil
    2861:	75 13                	jne    2876 <func4+0x29>
    2863:	89 f0                	mov    %esi,%eax
    2865:	c1 e8 1f             	shr    $0x1f,%eax
    2868:	01 c6                	add    %eax,%esi
    286a:	d1 fe                	sar    %esi
    286c:	e8 dc ff ff ff       	call   284d <func4>
    2871:	0f af c0             	imul   %eax,%eax
    2874:	5b                   	pop    %rbx
    2875:	c3                   	ret    
    2876:	83 ee 01             	sub    $0x1,%esi
    2879:	89 f0                	mov    %esi,%eax
    287b:	c1 e8 1f             	shr    $0x1f,%eax
    287e:	01 c6                	add    %eax,%esi
    2880:	d1 fe                	sar    %esi
    2882:	e8 c6 ff ff ff       	call   284d <func4>
    2887:	89 da                	mov    %ebx,%edx
    2889:	0f af d0             	imul   %eax,%edx
    288c:	0f af c2             	imul   %edx,%eax
    288f:	eb e3                	jmp    2874 <func4+0x27>
    2891:	c3                   	ret    

0000000000002892 <phase_4>:
    2892:	f3 0f 1e fa          	endbr64 
    2896:	48 83 ec 18          	sub    $0x18,%rsp
    289a:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    28a1:	00 00 
    28a3:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    28a8:	31 c0                	xor    %eax,%eax
    28aa:	48 8d 4c 24 04       	lea    0x4(%rsp),%rcx
    28af:	48 89 e2             	mov    %rsp,%rdx
    28b2:	48 8d 35 74 24 00 00 	lea    0x2474(%rip),%rsi        # 4d2d <array.0+0xb8d>
    28b9:	e8 72 fa ff ff       	call   2330 <__isoc99_sscanf@plt>
    28be:	83 f8 02             	cmp    $0x2,%eax
    28c1:	75 0d                	jne    28d0 <phase_4+0x3e>
    28c3:	83 3c 24 01          	cmpl   $0x1,(%rsp)
    28c7:	7e 07                	jle    28d0 <phase_4+0x3e>
    28c9:	83 7c 24 04 01       	cmpl   $0x1,0x4(%rsp)
    28ce:	7f 05                	jg     28d5 <phase_4+0x43>
    28d0:	e8 9a 08 00 00       	call   316f <explode_bomb>
    28d5:	be 07 00 00 00       	mov    $0x7,%esi
    28da:	8b 3c 24             	mov    (%rsp),%edi
    28dd:	e8 6b ff ff ff       	call   284d <func4>
    28e2:	39 44 24 04          	cmp    %eax,0x4(%rsp)
    28e6:	75 15                	jne    28fd <phase_4+0x6b>
    28e8:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    28ed:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    28f4:	00 00 
    28f6:	75 0c                	jne    2904 <phase_4+0x72>
    28f8:	48 83 c4 18          	add    $0x18,%rsp
    28fc:	c3                   	ret    
    28fd:	e8 6d 08 00 00       	call   316f <explode_bomb>
    2902:	eb e4                	jmp    28e8 <phase_4+0x56>
    2904:	e8 77 f9 ff ff       	call   2280 <__stack_chk_fail@plt>

0000000000002909 <phase_5>:
    2909:	f3 0f 1e fa          	endbr64 
    290d:	48 83 ec 18          	sub    $0x18,%rsp
    2911:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    2918:	00 00 
    291a:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    291f:	31 c0                	xor    %eax,%eax
    2921:	48 8d 4c 24 04       	lea    0x4(%rsp),%rcx
    2926:	48 89 e2             	mov    %rsp,%rdx
    2929:	48 8d 35 fd 23 00 00 	lea    0x23fd(%rip),%rsi        # 4d2d <array.0+0xb8d>
    2930:	e8 fb f9 ff ff       	call   2330 <__isoc99_sscanf@plt>
    2935:	83 f8 01             	cmp    $0x1,%eax
    2938:	7e 6b                	jle    29a5 <phase_5+0x9c>
    293a:	8b 14 24             	mov    (%rsp),%edx
    293d:	83 e2 0f             	and    $0xf,%edx
    2940:	89 14 24             	mov    %edx,(%rsp)
    2943:	48 63 ca             	movslq %edx,%rcx
    2946:	48 8d 05 53 18 00 00 	lea    0x1853(%rip),%rax        # 41a0 <array.0>
    294d:	8b 04 88             	mov    (%rax,%rcx,4),%eax
    2950:	83 f8 0f             	cmp    $0xf,%eax
    2953:	74 36                	je     298b <phase_5+0x82>
    2955:	be 00 00 00 00       	mov    $0x0,%esi
    295a:	b9 00 00 00 00       	mov    $0x0,%ecx
    295f:	48 8d 3d 3a 18 00 00 	lea    0x183a(%rip),%rdi        # 41a0 <array.0>
    2966:	83 c1 01             	add    $0x1,%ecx
    2969:	8d 74 16 01          	lea    0x1(%rsi,%rdx,1),%esi
    296d:	89 c2                	mov    %eax,%edx
    296f:	48 98                	cltq   
    2971:	8b 04 87             	mov    (%rdi,%rax,4),%eax
    2974:	83 f8 0f             	cmp    $0xf,%eax
    2977:	75 ed                	jne    2966 <phase_5+0x5d>
    2979:	89 14 24             	mov    %edx,(%rsp)
    297c:	83 f9 08             	cmp    $0x8,%ecx
    297f:	75 0a                	jne    298b <phase_5+0x82>
    2981:	8d 44 16 01          	lea    0x1(%rsi,%rdx,1),%eax
    2985:	39 44 24 04          	cmp    %eax,0x4(%rsp)
    2989:	74 05                	je     2990 <phase_5+0x87>
    298b:	e8 df 07 00 00       	call   316f <explode_bomb>
    2990:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    2995:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    299c:	00 00 
    299e:	75 0c                	jne    29ac <phase_5+0xa3>
    29a0:	48 83 c4 18          	add    $0x18,%rsp
    29a4:	c3                   	ret    
    29a5:	e8 c5 07 00 00       	call   316f <explode_bomb>
    29aa:	eb 8e                	jmp    293a <phase_5+0x31>
    29ac:	e8 cf f8 ff ff       	call   2280 <__stack_chk_fail@plt>

00000000000029b1 <phase_6>:
    29b1:	f3 0f 1e fa          	endbr64 
    29b5:	41 56                	push   %r14
    29b7:	41 55                	push   %r13
    29b9:	41 54                	push   %r12
    29bb:	55                   	push   %rbp
    29bc:	53                   	push   %rbx
    29bd:	48 83 ec 60          	sub    $0x60,%rsp
    29c1:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    29c8:	00 00 
    29ca:	48 89 44 24 58       	mov    %rax,0x58(%rsp)
    29cf:	31 c0                	xor    %eax,%eax
    29d1:	49 89 e5             	mov    %rsp,%r13
    29d4:	4c 89 ee             	mov    %r13,%rsi
    29d7:	e8 d5 07 00 00       	call   31b1 <read_six_numbers>
    29dc:	41 be 01 00 00 00    	mov    $0x1,%r14d
    29e2:	49 89 e4             	mov    %rsp,%r12
    29e5:	eb 28                	jmp    2a0f <phase_6+0x5e>
    29e7:	e8 83 07 00 00       	call   316f <explode_bomb>
    29ec:	eb 30                	jmp    2a1e <phase_6+0x6d>
    29ee:	48 83 c3 01          	add    $0x1,%rbx
    29f2:	83 fb 05             	cmp    $0x5,%ebx
    29f5:	7f 10                	jg     2a07 <phase_6+0x56>
    29f7:	41 8b 04 9c          	mov    (%r12,%rbx,4),%eax
    29fb:	39 45 00             	cmp    %eax,0x0(%rbp)
    29fe:	75 ee                	jne    29ee <phase_6+0x3d>
    2a00:	e8 6a 07 00 00       	call   316f <explode_bomb>
    2a05:	eb e7                	jmp    29ee <phase_6+0x3d>
    2a07:	49 83 c6 01          	add    $0x1,%r14
    2a0b:	49 83 c5 04          	add    $0x4,%r13
    2a0f:	4c 89 ed             	mov    %r13,%rbp
    2a12:	41 8b 45 00          	mov    0x0(%r13),%eax
    2a16:	83 e8 01             	sub    $0x1,%eax
    2a19:	83 f8 05             	cmp    $0x5,%eax
    2a1c:	77 c9                	ja     29e7 <phase_6+0x36>
    2a1e:	41 83 fe 05          	cmp    $0x5,%r14d
    2a22:	7f 05                	jg     2a29 <phase_6+0x78>
    2a24:	4c 89 f3             	mov    %r14,%rbx
    2a27:	eb ce                	jmp    29f7 <phase_6+0x46>
    2a29:	be 00 00 00 00       	mov    $0x0,%esi
    2a2e:	8b 0c b4             	mov    (%rsp,%rsi,4),%ecx
    2a31:	b8 01 00 00 00       	mov    $0x1,%eax
    2a36:	48 8d 15 f3 47 00 00 	lea    0x47f3(%rip),%rdx        # 7230 <node1>
    2a3d:	83 f9 01             	cmp    $0x1,%ecx
    2a40:	7e 0b                	jle    2a4d <phase_6+0x9c>
    2a42:	48 8b 52 08          	mov    0x8(%rdx),%rdx
    2a46:	83 c0 01             	add    $0x1,%eax
    2a49:	39 c8                	cmp    %ecx,%eax
    2a4b:	75 f5                	jne    2a42 <phase_6+0x91>
    2a4d:	48 89 54 f4 20       	mov    %rdx,0x20(%rsp,%rsi,8)
    2a52:	48 83 c6 01          	add    $0x1,%rsi
    2a56:	48 83 fe 06          	cmp    $0x6,%rsi
    2a5a:	75 d2                	jne    2a2e <phase_6+0x7d>
    2a5c:	48 8b 5c 24 20       	mov    0x20(%rsp),%rbx
    2a61:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    2a66:	48 89 43 08          	mov    %rax,0x8(%rbx)
    2a6a:	48 8b 54 24 30       	mov    0x30(%rsp),%rdx
    2a6f:	48 89 50 08          	mov    %rdx,0x8(%rax)
    2a73:	48 8b 44 24 38       	mov    0x38(%rsp),%rax
    2a78:	48 89 42 08          	mov    %rax,0x8(%rdx)
    2a7c:	48 8b 54 24 40       	mov    0x40(%rsp),%rdx
    2a81:	48 89 50 08          	mov    %rdx,0x8(%rax)
    2a85:	48 8b 44 24 48       	mov    0x48(%rsp),%rax
    2a8a:	48 89 42 08          	mov    %rax,0x8(%rdx)
    2a8e:	48 c7 40 08 00 00 00 	movq   $0x0,0x8(%rax)
    2a95:	00 
    2a96:	bd 03 00 00 00       	mov    $0x3,%ebp
    2a9b:	eb 09                	jmp    2aa6 <phase_6+0xf5>
    2a9d:	48 8b 5b 08          	mov    0x8(%rbx),%rbx
    2aa1:	83 ed 01             	sub    $0x1,%ebp
    2aa4:	74 11                	je     2ab7 <phase_6+0x106>
    2aa6:	48 8b 43 08          	mov    0x8(%rbx),%rax
    2aaa:	8b 00                	mov    (%rax),%eax
    2aac:	39 03                	cmp    %eax,(%rbx)
    2aae:	7d ed                	jge    2a9d <phase_6+0xec>
    2ab0:	e8 ba 06 00 00       	call   316f <explode_bomb>
    2ab5:	eb e6                	jmp    2a9d <phase_6+0xec>
    2ab7:	48 8b 43 08          	mov    0x8(%rbx),%rax
    2abb:	8b 00                	mov    (%rax),%eax
    2abd:	39 03                	cmp    %eax,(%rbx)
    2abf:	7f 2b                	jg     2aec <phase_6+0x13b>
    2ac1:	48 8b 43 08          	mov    0x8(%rbx),%rax
    2ac5:	48 8b 50 08          	mov    0x8(%rax),%rdx
    2ac9:	8b 3a                	mov    (%rdx),%edi
    2acb:	39 38                	cmp    %edi,(%rax)
    2acd:	7f 24                	jg     2af3 <phase_6+0x142>
    2acf:	48 8b 44 24 58       	mov    0x58(%rsp),%rax
    2ad4:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    2adb:	00 00 
    2add:	75 1b                	jne    2afa <phase_6+0x149>
    2adf:	48 83 c4 60          	add    $0x60,%rsp
    2ae3:	5b                   	pop    %rbx
    2ae4:	5d                   	pop    %rbp
    2ae5:	41 5c                	pop    %r12
    2ae7:	41 5d                	pop    %r13
    2ae9:	41 5e                	pop    %r14
    2aeb:	c3                   	ret    
    2aec:	e8 7e 06 00 00       	call   316f <explode_bomb>
    2af1:	eb ce                	jmp    2ac1 <phase_6+0x110>
    2af3:	e8 77 06 00 00       	call   316f <explode_bomb>
    2af8:	eb d5                	jmp    2acf <phase_6+0x11e>
    2afa:	e8 81 f7 ff ff       	call   2280 <__stack_chk_fail@plt>

0000000000002aff <fun7>:
    2aff:	f3 0f 1e fa          	endbr64 
    2b03:	48 85 ff             	test   %rdi,%rdi
    2b06:	74 40                	je     2b48 <fun7+0x49>
    2b08:	41 54                	push   %r12
    2b0a:	55                   	push   %rbp
    2b0b:	53                   	push   %rbx
    2b0c:	48 89 fb             	mov    %rdi,%rbx
    2b0f:	89 f5                	mov    %esi,%ebp
    2b11:	b8 00 00 00 00       	mov    $0x0,%eax
    2b16:	39 37                	cmp    %esi,(%rdi)
    2b18:	74 22                	je     2b3c <fun7+0x3d>
    2b1a:	48 8b 7f 08          	mov    0x8(%rdi),%rdi
    2b1e:	e8 dc ff ff ff       	call   2aff <fun7>
    2b23:	41 89 c4             	mov    %eax,%r12d
    2b26:	48 8b 7b 10          	mov    0x10(%rbx),%rdi
    2b2a:	89 ee                	mov    %ebp,%esi
    2b2c:	e8 ce ff ff ff       	call   2aff <fun7>
    2b31:	45 85 e4             	test   %r12d,%r12d
    2b34:	79 0b                	jns    2b41 <fun7+0x42>
    2b36:	85 c0                	test   %eax,%eax
    2b38:	78 14                	js     2b4e <fun7+0x4f>
    2b3a:	01 c0                	add    %eax,%eax
    2b3c:	5b                   	pop    %rbx
    2b3d:	5d                   	pop    %rbp
    2b3e:	41 5c                	pop    %r12
    2b40:	c3                   	ret    
    2b41:	43 8d 44 24 01       	lea    0x1(%r12,%r12,1),%eax
    2b46:	eb f4                	jmp    2b3c <fun7+0x3d>
    2b48:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2b4d:	c3                   	ret    
    2b4e:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2b53:	eb e7                	jmp    2b3c <fun7+0x3d>

0000000000002b55 <secret_phase>:
    2b55:	f3 0f 1e fa          	endbr64 
    2b59:	53                   	push   %rbx
    2b5a:	e8 97 06 00 00       	call   31f6 <read_line>
    2b5f:	48 89 c7             	mov    %rax,%rdi
    2b62:	ba 0a 00 00 00       	mov    $0xa,%edx
    2b67:	be 00 00 00 00       	mov    $0x0,%esi
    2b6c:	e8 9f f7 ff ff       	call   2310 <strtol@plt>
    2b71:	89 c3                	mov    %eax,%ebx
    2b73:	83 e8 32             	sub    $0x32,%eax
    2b76:	3d b6 03 00 00       	cmp    $0x3b6,%eax
    2b7b:	77 30                	ja     2bad <secret_phase+0x58>
    2b7d:	89 de                	mov    %ebx,%esi
    2b7f:	48 8d 3d ca 45 00 00 	lea    0x45ca(%rip),%rdi        # 7150 <n1>
    2b86:	e8 74 ff ff ff       	call   2aff <fun7>
    2b8b:	83 f8 06             	cmp    $0x6,%eax
    2b8e:	75 24                	jne    2bb4 <secret_phase+0x5f>
    2b90:	48 8d 3d 49 16 00 00 	lea    0x1649(%rip),%rdi        # 41e0 <array.0+0x40>
    2b97:	e8 b4 f6 ff ff       	call   2250 <puts@plt>
    2b9c:	b8 00 00 00 00       	mov    $0x0,%eax
    2ba1:	e8 2e 02 00 00       	call   2dd4 <print_special>
    2ba6:	e8 85 07 00 00       	call   3330 <phase_defused>
    2bab:	5b                   	pop    %rbx
    2bac:	c3                   	ret    
    2bad:	e8 bd 05 00 00       	call   316f <explode_bomb>
    2bb2:	eb c9                	jmp    2b7d <secret_phase+0x28>
    2bb4:	e8 b6 05 00 00       	call   316f <explode_bomb>
    2bb9:	eb d5                	jmp    2b90 <secret_phase+0x3b>

0000000000002bbb <sig_handler>:
    2bbb:	f3 0f 1e fa          	endbr64 
    2bbf:	50                   	push   %rax
    2bc0:	58                   	pop    %rax
    2bc1:	48 83 ec 08          	sub    $0x8,%rsp
    2bc5:	48 8d 3d 3c 16 00 00 	lea    0x163c(%rip),%rdi        # 4208 <array.0+0x68>
    2bcc:	e8 7f f6 ff ff       	call   2250 <puts@plt>
    2bd1:	bf 03 00 00 00       	mov    $0x3,%edi
    2bd6:	e8 c5 f7 ff ff       	call   23a0 <sleep@plt>
    2bdb:	48 8d 35 c7 20 00 00 	lea    0x20c7(%rip),%rsi        # 4ca9 <array.0+0xb09>
    2be2:	bf 01 00 00 00       	mov    $0x1,%edi
    2be7:	b8 00 00 00 00       	mov    $0x0,%eax
    2bec:	e8 4f f7 ff ff       	call   2340 <__printf_chk@plt>
    2bf1:	48 8b 3d 68 4e 00 00 	mov    0x4e68(%rip),%rdi        # 7a60 <stdout@GLIBC_2.2.5>
    2bf8:	e8 23 f7 ff ff       	call   2320 <fflush@plt>
    2bfd:	bf 01 00 00 00       	mov    $0x1,%edi
    2c02:	e8 99 f7 ff ff       	call   23a0 <sleep@plt>
    2c07:	48 8d 3d a3 20 00 00 	lea    0x20a3(%rip),%rdi        # 4cb1 <array.0+0xb11>
    2c0e:	e8 3d f6 ff ff       	call   2250 <puts@plt>
    2c13:	bf 10 00 00 00       	mov    $0x10,%edi
    2c18:	e8 53 f7 ff ff       	call   2370 <exit@plt>

0000000000002c1d <invalid_phase>:
    2c1d:	f3 0f 1e fa          	endbr64 
    2c21:	50                   	push   %rax
    2c22:	58                   	pop    %rax
    2c23:	48 83 ec 08          	sub    $0x8,%rsp
    2c27:	48 89 fa             	mov    %rdi,%rdx
    2c2a:	48 8d 35 88 20 00 00 	lea    0x2088(%rip),%rsi        # 4cb9 <array.0+0xb19>
    2c31:	bf 01 00 00 00       	mov    $0x1,%edi
    2c36:	b8 00 00 00 00       	mov    $0x0,%eax
    2c3b:	e8 00 f7 ff ff       	call   2340 <__printf_chk@plt>
    2c40:	bf 08 00 00 00       	mov    $0x8,%edi
    2c45:	e8 26 f7 ff ff       	call   2370 <exit@plt>

0000000000002c4a <string_length>:
    2c4a:	f3 0f 1e fa          	endbr64 
    2c4e:	80 3f 00             	cmpb   $0x0,(%rdi)
    2c51:	74 12                	je     2c65 <string_length+0x1b>
    2c53:	b8 00 00 00 00       	mov    $0x0,%eax
    2c58:	48 83 c7 01          	add    $0x1,%rdi
    2c5c:	83 c0 01             	add    $0x1,%eax
    2c5f:	80 3f 00             	cmpb   $0x0,(%rdi)
    2c62:	75 f4                	jne    2c58 <string_length+0xe>
    2c64:	c3                   	ret    
    2c65:	b8 00 00 00 00       	mov    $0x0,%eax
    2c6a:	c3                   	ret    

0000000000002c6b <check_division_equal>:
    2c6b:	f3 0f 1e fa          	endbr64 
    2c6f:	89 f8                	mov    %edi,%eax
    2c71:	89 d1                	mov    %edx,%ecx
    2c73:	99                   	cltd   
    2c74:	f7 fe                	idiv   %esi
    2c76:	39 c8                	cmp    %ecx,%eax
    2c78:	0f 94 c0             	sete   %al
    2c7b:	0f b6 c0             	movzbl %al,%eax
    2c7e:	c3                   	ret    

0000000000002c7f <check_multiplication_equal>:
    2c7f:	f3 0f 1e fa          	endbr64 
    2c83:	0f af fe             	imul   %esi,%edi
    2c86:	39 d7                	cmp    %edx,%edi
    2c88:	0f 94 c0             	sete   %al
    2c8b:	0f b6 c0             	movzbl %al,%eax
    2c8e:	c3                   	ret    

0000000000002c8f <check_substraction_equal>:
    2c8f:	f3 0f 1e fa          	endbr64 
    2c93:	29 f7                	sub    %esi,%edi
    2c95:	39 d7                	cmp    %edx,%edi
    2c97:	0f 94 c0             	sete   %al
    2c9a:	0f b6 c0             	movzbl %al,%eax
    2c9d:	c3                   	ret    

0000000000002c9e <check_modulus_equal>:
    2c9e:	f3 0f 1e fa          	endbr64 
    2ca2:	89 f8                	mov    %edi,%eax
    2ca4:	89 d1                	mov    %edx,%ecx
    2ca6:	99                   	cltd   
    2ca7:	f7 fe                	idiv   %esi
    2ca9:	39 ca                	cmp    %ecx,%edx
    2cab:	0f 94 c0             	sete   %al
    2cae:	0f b6 c0             	movzbl %al,%eax
    2cb1:	c3                   	ret    

0000000000002cb2 <check_power_equal>:
    2cb2:	f3 0f 1e fa          	endbr64 
    2cb6:	8d 46 ff             	lea    -0x1(%rsi),%eax
    2cb9:	83 fe 01             	cmp    $0x1,%esi
    2cbc:	7e 13                	jle    2cd1 <check_power_equal+0x1f>
    2cbe:	89 f9                	mov    %edi,%ecx
    2cc0:	0f af cf             	imul   %edi,%ecx
    2cc3:	83 e8 01             	sub    $0x1,%eax
    2cc6:	75 f8                	jne    2cc0 <check_power_equal+0xe>
    2cc8:	39 ca                	cmp    %ecx,%edx
    2cca:	0f 94 c0             	sete   %al
    2ccd:	0f b6 c0             	movzbl %al,%eax
    2cd0:	c3                   	ret    
    2cd1:	89 f9                	mov    %edi,%ecx
    2cd3:	eb f3                	jmp    2cc8 <check_power_equal+0x16>

0000000000002cd5 <reverse_string>:
    2cd5:	f3 0f 1e fa          	endbr64 
    2cd9:	53                   	push   %rbx
    2cda:	48 89 fb             	mov    %rdi,%rbx
    2cdd:	48 85 ff             	test   %rdi,%rdi
    2ce0:	74 31                	je     2d13 <reverse_string+0x3e>
    2ce2:	80 3f 00             	cmpb   $0x0,(%rdi)
    2ce5:	74 2c                	je     2d13 <reverse_string+0x3e>
    2ce7:	e8 84 f5 ff ff       	call   2270 <strlen@plt>
    2cec:	48 8d 4c 03 ff       	lea    -0x1(%rbx,%rax,1),%rcx
    2cf1:	48 39 cb             	cmp    %rcx,%rbx
    2cf4:	73 1d                	jae    2d13 <reverse_string+0x3e>
    2cf6:	48 89 da             	mov    %rbx,%rdx
    2cf9:	0f b6 02             	movzbl (%rdx),%eax
    2cfc:	32 01                	xor    (%rcx),%al
    2cfe:	88 02                	mov    %al,(%rdx)
    2d00:	32 01                	xor    (%rcx),%al
    2d02:	88 01                	mov    %al,(%rcx)
    2d04:	30 02                	xor    %al,(%rdx)
    2d06:	48 83 c2 01          	add    $0x1,%rdx
    2d0a:	48 83 e9 01          	sub    $0x1,%rcx
    2d0e:	48 39 ca             	cmp    %rcx,%rdx
    2d11:	72 e6                	jb     2cf9 <reverse_string+0x24>
    2d13:	48 89 d8             	mov    %rbx,%rax
    2d16:	5b                   	pop    %rbx
    2d17:	c3                   	ret    

0000000000002d18 <strings_not_equal>:
    2d18:	f3 0f 1e fa          	endbr64 
    2d1c:	41 54                	push   %r12
    2d1e:	55                   	push   %rbp
    2d1f:	53                   	push   %rbx
    2d20:	48 89 fb             	mov    %rdi,%rbx
    2d23:	48 89 f5             	mov    %rsi,%rbp
    2d26:	e8 1f ff ff ff       	call   2c4a <string_length>
    2d2b:	41 89 c4             	mov    %eax,%r12d
    2d2e:	48 89 ef             	mov    %rbp,%rdi
    2d31:	e8 14 ff ff ff       	call   2c4a <string_length>
    2d36:	89 c2                	mov    %eax,%edx
    2d38:	b8 01 00 00 00       	mov    $0x1,%eax
    2d3d:	41 39 d4             	cmp    %edx,%r12d
    2d40:	75 31                	jne    2d73 <strings_not_equal+0x5b>
    2d42:	0f b6 13             	movzbl (%rbx),%edx
    2d45:	84 d2                	test   %dl,%dl
    2d47:	74 1e                	je     2d67 <strings_not_equal+0x4f>
    2d49:	b8 00 00 00 00       	mov    $0x0,%eax
    2d4e:	38 54 05 00          	cmp    %dl,0x0(%rbp,%rax,1)
    2d52:	75 1a                	jne    2d6e <strings_not_equal+0x56>
    2d54:	48 83 c0 01          	add    $0x1,%rax
    2d58:	0f b6 14 03          	movzbl (%rbx,%rax,1),%edx
    2d5c:	84 d2                	test   %dl,%dl
    2d5e:	75 ee                	jne    2d4e <strings_not_equal+0x36>
    2d60:	b8 00 00 00 00       	mov    $0x0,%eax
    2d65:	eb 0c                	jmp    2d73 <strings_not_equal+0x5b>
    2d67:	b8 00 00 00 00       	mov    $0x0,%eax
    2d6c:	eb 05                	jmp    2d73 <strings_not_equal+0x5b>
    2d6e:	b8 01 00 00 00       	mov    $0x1,%eax
    2d73:	5b                   	pop    %rbx
    2d74:	5d                   	pop    %rbp
    2d75:	41 5c                	pop    %r12
    2d77:	c3                   	ret    

0000000000002d78 <strings_cat>:
    2d78:	f3 0f 1e fa          	endbr64 
    2d7c:	80 3f 00             	cmpb   $0x0,(%rdi)
    2d7f:	74 09                	je     2d8a <strings_cat+0x12>
    2d81:	48 83 c7 01          	add    $0x1,%rdi
    2d85:	80 3f 00             	cmpb   $0x0,(%rdi)
    2d88:	75 f7                	jne    2d81 <strings_cat+0x9>
    2d8a:	0f b6 16             	movzbl (%rsi),%edx
    2d8d:	84 d2                	test   %dl,%dl
    2d8f:	74 14                	je     2da5 <strings_cat+0x2d>
    2d91:	b8 00 00 00 00       	mov    $0x0,%eax
    2d96:	88 14 07             	mov    %dl,(%rdi,%rax,1)
    2d99:	48 83 c0 01          	add    $0x1,%rax
    2d9d:	0f b6 14 06          	movzbl (%rsi,%rax,1),%edx
    2da1:	84 d2                	test   %dl,%dl
    2da3:	75 f1                	jne    2d96 <strings_cat+0x1e>
    2da5:	c3                   	ret    

0000000000002da6 <from_char_to_int>:
    2da6:	f3 0f 1e fa          	endbr64 
    2daa:	40 0f be c7          	movsbl %dil,%eax
    2dae:	8d 57 9f             	lea    -0x61(%rdi),%edx
    2db1:	80 fa 19             	cmp    $0x19,%dl
    2db4:	77 04                	ja     2dba <from_char_to_int+0x14>
    2db6:	83 e8 04             	sub    $0x4,%eax
    2db9:	c3                   	ret    
    2dba:	8d 57 bf             	lea    -0x41(%rdi),%edx
    2dbd:	80 fa 19             	cmp    $0x19,%dl
    2dc0:	77 04                	ja     2dc6 <from_char_to_int+0x20>
    2dc2:	83 e8 06             	sub    $0x6,%eax
    2dc5:	c3                   	ret    
    2dc6:	83 ef 30             	sub    $0x30,%edi
    2dc9:	8d 50 fd             	lea    -0x3(%rax),%edx
    2dcc:	40 80 ff 0a          	cmp    $0xa,%dil
    2dd0:	0f 42 c2             	cmovb  %edx,%eax
    2dd3:	c3                   	ret    

0000000000002dd4 <print_special>:
    2dd4:	f3 0f 1e fa          	endbr64 
    2dd8:	48 83 ec 08          	sub    $0x8,%rsp
    2ddc:	48 8d 3d 5d 14 00 00 	lea    0x145d(%rip),%rdi        # 4240 <array.0+0xa0>
    2de3:	e8 68 f4 ff ff       	call   2250 <puts@plt>
    2de8:	48 8d 3d a1 14 00 00 	lea    0x14a1(%rip),%rdi        # 4290 <array.0+0xf0>
    2def:	e8 5c f4 ff ff       	call   2250 <puts@plt>
    2df4:	48 8d 3d dd 14 00 00 	lea    0x14dd(%rip),%rdi        # 42d8 <array.0+0x138>
    2dfb:	e8 50 f4 ff ff       	call   2250 <puts@plt>
    2e00:	48 8d 3d 21 15 00 00 	lea    0x1521(%rip),%rdi        # 4328 <array.0+0x188>
    2e07:	e8 44 f4 ff ff       	call   2250 <puts@plt>
    2e0c:	48 8d 3d 65 15 00 00 	lea    0x1565(%rip),%rdi        # 4378 <array.0+0x1d8>
    2e13:	e8 38 f4 ff ff       	call   2250 <puts@plt>
    2e18:	48 8d 3d b9 15 00 00 	lea    0x15b9(%rip),%rdi        # 43d8 <array.0+0x238>
    2e1f:	e8 2c f4 ff ff       	call   2250 <puts@plt>
    2e24:	48 8d 3d 15 16 00 00 	lea    0x1615(%rip),%rdi        # 4440 <array.0+0x2a0>
    2e2b:	e8 20 f4 ff ff       	call   2250 <puts@plt>
    2e30:	48 8d 3d 79 16 00 00 	lea    0x1679(%rip),%rdi        # 44b0 <array.0+0x310>
    2e37:	e8 14 f4 ff ff       	call   2250 <puts@plt>
    2e3c:	48 8d 3d dd 16 00 00 	lea    0x16dd(%rip),%rdi        # 4520 <array.0+0x380>
    2e43:	e8 08 f4 ff ff       	call   2250 <puts@plt>
    2e48:	48 8d 3d 59 17 00 00 	lea    0x1759(%rip),%rdi        # 45a8 <array.0+0x408>
    2e4f:	e8 fc f3 ff ff       	call   2250 <puts@plt>
    2e54:	48 8d 3d bd 17 00 00 	lea    0x17bd(%rip),%rdi        # 4618 <array.0+0x478>
    2e5b:	e8 f0 f3 ff ff       	call   2250 <puts@plt>
    2e60:	48 8d 3d 31 18 00 00 	lea    0x1831(%rip),%rdi        # 4698 <array.0+0x4f8>
    2e67:	e8 e4 f3 ff ff       	call   2250 <puts@plt>
    2e6c:	48 8d 3d a5 18 00 00 	lea    0x18a5(%rip),%rdi        # 4718 <array.0+0x578>
    2e73:	e8 d8 f3 ff ff       	call   2250 <puts@plt>
    2e78:	48 8d 3d 19 19 00 00 	lea    0x1919(%rip),%rdi        # 4798 <array.0+0x5f8>
    2e7f:	e8 cc f3 ff ff       	call   2250 <puts@plt>
    2e84:	48 8d 3d 85 19 00 00 	lea    0x1985(%rip),%rdi        # 4810 <array.0+0x670>
    2e8b:	e8 c0 f3 ff ff       	call   2250 <puts@plt>
    2e90:	48 8d 3d e1 19 00 00 	lea    0x19e1(%rip),%rdi        # 4878 <array.0+0x6d8>
    2e97:	e8 b4 f3 ff ff       	call   2250 <puts@plt>
    2e9c:	48 8d 3d 3d 1a 00 00 	lea    0x1a3d(%rip),%rdi        # 48e0 <array.0+0x740>
    2ea3:	e8 a8 f3 ff ff       	call   2250 <puts@plt>
    2ea8:	48 8d 3d 99 1a 00 00 	lea    0x1a99(%rip),%rdi        # 4948 <array.0+0x7a8>
    2eaf:	e8 9c f3 ff ff       	call   2250 <puts@plt>
    2eb4:	48 8d 3d 05 1b 00 00 	lea    0x1b05(%rip),%rdi        # 49c0 <array.0+0x820>
    2ebb:	e8 90 f3 ff ff       	call   2250 <puts@plt>
    2ec0:	48 8d 3d 79 1b 00 00 	lea    0x1b79(%rip),%rdi        # 4a40 <array.0+0x8a0>
    2ec7:	e8 84 f3 ff ff       	call   2250 <puts@plt>
    2ecc:	48 8d 3d ed 1b 00 00 	lea    0x1bed(%rip),%rdi        # 4ac0 <array.0+0x920>
    2ed3:	e8 78 f3 ff ff       	call   2250 <puts@plt>
    2ed8:	48 83 c4 08          	add    $0x8,%rsp
    2edc:	c3                   	ret    

0000000000002edd <initialize_bomb>:
    2edd:	f3 0f 1e fa          	endbr64 
    2ee1:	55                   	push   %rbp
    2ee2:	53                   	push   %rbx
    2ee3:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    2eea:	48 83 0c 24 00       	orq    $0x0,(%rsp)
    2eef:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    2ef6:	48 83 0c 24 00       	orq    $0x0,(%rsp)
    2efb:	48 83 ec 58          	sub    $0x58,%rsp
    2eff:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    2f06:	00 00 
    2f08:	48 89 84 24 48 20 00 	mov    %rax,0x2048(%rsp)
    2f0f:	00 
    2f10:	31 c0                	xor    %eax,%eax
    2f12:	48 8d 35 a2 fc ff ff 	lea    -0x35e(%rip),%rsi        # 2bbb <sig_handler>
    2f19:	bf 02 00 00 00       	mov    $0x2,%edi
    2f1e:	e8 bd f3 ff ff       	call   22e0 <signal@plt>
    2f23:	48 89 e7             	mov    %rsp,%rdi
    2f26:	be 40 00 00 00       	mov    $0x40,%esi
    2f2b:	e8 30 f4 ff ff       	call   2360 <gethostname@plt>
    2f30:	85 c0                	test   %eax,%eax
    2f32:	75 45                	jne    2f79 <initialize_bomb+0x9c>
    2f34:	48 8b 3d 45 43 00 00 	mov    0x4345(%rip),%rdi        # 7280 <host_table>
    2f3b:	48 8d 1d 46 43 00 00 	lea    0x4346(%rip),%rbx        # 7288 <host_table+0x8>
    2f42:	48 89 e5             	mov    %rsp,%rbp
    2f45:	48 85 ff             	test   %rdi,%rdi
    2f48:	74 19                	je     2f63 <initialize_bomb+0x86>
    2f4a:	48 89 ee             	mov    %rbp,%rsi
    2f4d:	e8 ce f2 ff ff       	call   2220 <strcasecmp@plt>
    2f52:	85 c0                	test   %eax,%eax
    2f54:	74 5e                	je     2fb4 <initialize_bomb+0xd7>
    2f56:	48 83 c3 08          	add    $0x8,%rbx
    2f5a:	48 8b 7b f8          	mov    -0x8(%rbx),%rdi
    2f5e:	48 85 ff             	test   %rdi,%rdi
    2f61:	75 e7                	jne    2f4a <initialize_bomb+0x6d>
    2f63:	48 8d 3d 0e 1c 00 00 	lea    0x1c0e(%rip),%rdi        # 4b78 <array.0+0x9d8>
    2f6a:	e8 e1 f2 ff ff       	call   2250 <puts@plt>
    2f6f:	bf 08 00 00 00       	mov    $0x8,%edi
    2f74:	e8 f7 f3 ff ff       	call   2370 <exit@plt>
    2f79:	48 8d 3d c0 1b 00 00 	lea    0x1bc0(%rip),%rdi        # 4b40 <array.0+0x9a0>
    2f80:	e8 cb f2 ff ff       	call   2250 <puts@plt>
    2f85:	bf 08 00 00 00       	mov    $0x8,%edi
    2f8a:	e8 e1 f3 ff ff       	call   2370 <exit@plt>
    2f8f:	48 8d 54 24 40       	lea    0x40(%rsp),%rdx
    2f94:	48 8d 35 2f 1d 00 00 	lea    0x1d2f(%rip),%rsi        # 4cca <array.0+0xb2a>
    2f9b:	bf 01 00 00 00       	mov    $0x1,%edi
    2fa0:	b8 00 00 00 00       	mov    $0x0,%eax
    2fa5:	e8 96 f3 ff ff       	call   2340 <__printf_chk@plt>
    2faa:	bf 08 00 00 00       	mov    $0x8,%edi
    2faf:	e8 bc f3 ff ff       	call   2370 <exit@plt>
    2fb4:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
    2fb9:	e8 76 0d 00 00       	call   3d34 <init_driver>
    2fbe:	85 c0                	test   %eax,%eax
    2fc0:	78 cd                	js     2f8f <initialize_bomb+0xb2>
    2fc2:	48 8b 84 24 48 20 00 	mov    0x2048(%rsp),%rax
    2fc9:	00 
    2fca:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    2fd1:	00 00 
    2fd3:	75 0a                	jne    2fdf <initialize_bomb+0x102>
    2fd5:	48 81 c4 58 20 00 00 	add    $0x2058,%rsp
    2fdc:	5b                   	pop    %rbx
    2fdd:	5d                   	pop    %rbp
    2fde:	c3                   	ret    
    2fdf:	e8 9c f2 ff ff       	call   2280 <__stack_chk_fail@plt>

0000000000002fe4 <initialize_bomb_solve>:
    2fe4:	f3 0f 1e fa          	endbr64 
    2fe8:	c3                   	ret    

0000000000002fe9 <blank_line>:
    2fe9:	f3 0f 1e fa          	endbr64 
    2fed:	55                   	push   %rbp
    2fee:	53                   	push   %rbx
    2fef:	48 83 ec 08          	sub    $0x8,%rsp
    2ff3:	48 89 fd             	mov    %rdi,%rbp
    2ff6:	0f b6 5d 00          	movzbl 0x0(%rbp),%ebx
    2ffa:	84 db                	test   %bl,%bl
    2ffc:	74 1e                	je     301c <blank_line+0x33>
    2ffe:	e8 ad f3 ff ff       	call   23b0 <__ctype_b_loc@plt>
    3003:	48 83 c5 01          	add    $0x1,%rbp
    3007:	48 0f be db          	movsbq %bl,%rbx
    300b:	48 8b 00             	mov    (%rax),%rax
    300e:	f6 44 58 01 20       	testb  $0x20,0x1(%rax,%rbx,2)
    3013:	75 e1                	jne    2ff6 <blank_line+0xd>
    3015:	b8 00 00 00 00       	mov    $0x0,%eax
    301a:	eb 05                	jmp    3021 <blank_line+0x38>
    301c:	b8 01 00 00 00       	mov    $0x1,%eax
    3021:	48 83 c4 08          	add    $0x8,%rsp
    3025:	5b                   	pop    %rbx
    3026:	5d                   	pop    %rbp
    3027:	c3                   	ret    

0000000000003028 <skip>:
    3028:	f3 0f 1e fa          	endbr64 
    302c:	55                   	push   %rbp
    302d:	53                   	push   %rbx
    302e:	48 83 ec 08          	sub    $0x8,%rsp
    3032:	48 8d 2d e7 4a 00 00 	lea    0x4ae7(%rip),%rbp        # 7b20 <input_strings>
    3039:	48 63 05 c4 4a 00 00 	movslq 0x4ac4(%rip),%rax        # 7b04 <num_input_strings>
    3040:	48 8d 04 80          	lea    (%rax,%rax,4),%rax
    3044:	48 8d 04 80          	lea    (%rax,%rax,4),%rax
    3048:	48 8d 7c 85 00       	lea    0x0(%rbp,%rax,4),%rdi
    304d:	48 8b 15 3c 4a 00 00 	mov    0x4a3c(%rip),%rdx        # 7a90 <infile>
    3054:	be 64 00 00 00       	mov    $0x64,%esi
    3059:	e8 62 f2 ff ff       	call   22c0 <fgets@plt>
    305e:	48 89 c3             	mov    %rax,%rbx
    3061:	48 85 c0             	test   %rax,%rax
    3064:	74 0c                	je     3072 <skip+0x4a>
    3066:	48 89 c7             	mov    %rax,%rdi
    3069:	e8 7b ff ff ff       	call   2fe9 <blank_line>
    306e:	85 c0                	test   %eax,%eax
    3070:	75 c7                	jne    3039 <skip+0x11>
    3072:	48 89 d8             	mov    %rbx,%rax
    3075:	48 83 c4 08          	add    $0x8,%rsp
    3079:	5b                   	pop    %rbx
    307a:	5d                   	pop    %rbp
    307b:	c3                   	ret    

000000000000307c <send_msg>:
    307c:	f3 0f 1e fa          	endbr64 
    3080:	53                   	push   %rbx
    3081:	4c 8d 9c 24 00 c0 ff 	lea    -0x4000(%rsp),%r11
    3088:	ff 
    3089:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    3090:	48 83 0c 24 00       	orq    $0x0,(%rsp)
    3095:	4c 39 dc             	cmp    %r11,%rsp
    3098:	75 ef                	jne    3089 <send_msg+0xd>
    309a:	48 83 ec 10          	sub    $0x10,%rsp
    309e:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    30a5:	00 00 
    30a7:	48 89 84 24 08 40 00 	mov    %rax,0x4008(%rsp)
    30ae:	00 
    30af:	31 c0                	xor    %eax,%eax
    30b1:	8b 15 4d 4a 00 00    	mov    0x4a4d(%rip),%edx        # 7b04 <num_input_strings>
    30b7:	8d 42 ff             	lea    -0x1(%rdx),%eax
    30ba:	48 98                	cltq   
    30bc:	48 8d 04 80          	lea    (%rax,%rax,4),%rax
    30c0:	48 8d 0c 80          	lea    (%rax,%rax,4),%rcx
    30c4:	48 8d 05 55 4a 00 00 	lea    0x4a55(%rip),%rax        # 7b20 <input_strings>
    30cb:	48 8d 04 88          	lea    (%rax,%rcx,4),%rax
    30cf:	85 ff                	test   %edi,%edi
    30d1:	4c 8d 0d 0c 1c 00 00 	lea    0x1c0c(%rip),%r9        # 4ce4 <array.0+0xb44>
    30d8:	48 8d 0d 0d 1c 00 00 	lea    0x1c0d(%rip),%rcx        # 4cec <array.0+0xb4c>
    30df:	4c 0f 44 c9          	cmove  %rcx,%r9
    30e3:	48 89 e3             	mov    %rsp,%rbx
    30e6:	50                   	push   %rax
    30e7:	52                   	push   %rdx
    30e8:	44 8b 05 51 40 00 00 	mov    0x4051(%rip),%r8d        # 7140 <bomb_id>
    30ef:	48 8d 0d ff 1b 00 00 	lea    0x1bff(%rip),%rcx        # 4cf5 <array.0+0xb55>
    30f6:	ba 00 20 00 00       	mov    $0x2000,%edx
    30fb:	be 01 00 00 00       	mov    $0x1,%esi
    3100:	48 89 df             	mov    %rbx,%rdi
    3103:	b8 00 00 00 00       	mov    $0x0,%eax
    3108:	e8 b3 f2 ff ff       	call   23c0 <__sprintf_chk@plt>
    310d:	4c 8d 84 24 10 20 00 	lea    0x2010(%rsp),%r8
    3114:	00 
    3115:	b9 00 00 00 00       	mov    $0x0,%ecx
    311a:	48 89 da             	mov    %rbx,%rdx
    311d:	48 8d 35 fc 3f 00 00 	lea    0x3ffc(%rip),%rsi        # 7120 <user_password>
    3124:	48 8d 3d 0d 40 00 00 	lea    0x400d(%rip),%rdi        # 7138 <userid>
    312b:	e8 f9 0d 00 00       	call   3f29 <driver_post>
    3130:	48 89 dc             	mov    %rbx,%rsp
    3133:	85 c0                	test   %eax,%eax
    3135:	78 1c                	js     3153 <send_msg+0xd7>
    3137:	48 8b 84 24 08 40 00 	mov    0x4008(%rsp),%rax
    313e:	00 
    313f:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    3146:	00 00 
    3148:	75 20                	jne    316a <send_msg+0xee>
    314a:	48 81 c4 10 40 00 00 	add    $0x4010,%rsp
    3151:	5b                   	pop    %rbx
    3152:	c3                   	ret    
    3153:	48 8d bc 24 00 20 00 	lea    0x2000(%rsp),%rdi
    315a:	00 
    315b:	e8 f0 f0 ff ff       	call   2250 <puts@plt>
    3160:	bf 00 00 00 00       	mov    $0x0,%edi
    3165:	e8 06 f2 ff ff       	call   2370 <exit@plt>
    316a:	e8 11 f1 ff ff       	call   2280 <__stack_chk_fail@plt>

000000000000316f <explode_bomb>:
    316f:	f3 0f 1e fa          	endbr64 
    3173:	50                   	push   %rax
    3174:	58                   	pop    %rax
    3175:	48 83 ec 08          	sub    $0x8,%rsp
    3179:	48 8d 3d 81 1b 00 00 	lea    0x1b81(%rip),%rdi        # 4d01 <array.0+0xb61>
    3180:	e8 cb f0 ff ff       	call   2250 <puts@plt>
    3185:	48 8d 3d 7e 1b 00 00 	lea    0x1b7e(%rip),%rdi        # 4d0a <array.0+0xb6a>
    318c:	e8 bf f0 ff ff       	call   2250 <puts@plt>
    3191:	bf 00 00 00 00       	mov    $0x0,%edi
    3196:	e8 e1 fe ff ff       	call   307c <send_msg>
    319b:	48 8d 3d 0e 1a 00 00 	lea    0x1a0e(%rip),%rdi        # 4bb0 <array.0+0xa10>
    31a2:	e8 a9 f0 ff ff       	call   2250 <puts@plt>
    31a7:	bf 08 00 00 00       	mov    $0x8,%edi
    31ac:	e8 bf f1 ff ff       	call   2370 <exit@plt>

00000000000031b1 <read_six_numbers>:
    31b1:	f3 0f 1e fa          	endbr64 
    31b5:	48 83 ec 08          	sub    $0x8,%rsp
    31b9:	48 89 f2             	mov    %rsi,%rdx
    31bc:	48 8d 4e 04          	lea    0x4(%rsi),%rcx
    31c0:	48 8d 46 14          	lea    0x14(%rsi),%rax
    31c4:	50                   	push   %rax
    31c5:	48 8d 46 10          	lea    0x10(%rsi),%rax
    31c9:	50                   	push   %rax
    31ca:	4c 8d 4e 0c          	lea    0xc(%rsi),%r9
    31ce:	4c 8d 46 08          	lea    0x8(%rsi),%r8
    31d2:	48 8d 35 48 1b 00 00 	lea    0x1b48(%rip),%rsi        # 4d21 <array.0+0xb81>
    31d9:	b8 00 00 00 00       	mov    $0x0,%eax
    31de:	e8 4d f1 ff ff       	call   2330 <__isoc99_sscanf@plt>
    31e3:	48 83 c4 10          	add    $0x10,%rsp
    31e7:	83 f8 05             	cmp    $0x5,%eax
    31ea:	7e 05                	jle    31f1 <read_six_numbers+0x40>
    31ec:	48 83 c4 08          	add    $0x8,%rsp
    31f0:	c3                   	ret    
    31f1:	e8 79 ff ff ff       	call   316f <explode_bomb>

00000000000031f6 <read_line>:
    31f6:	f3 0f 1e fa          	endbr64 
    31fa:	55                   	push   %rbp
    31fb:	53                   	push   %rbx
    31fc:	48 83 ec 08          	sub    $0x8,%rsp
    3200:	b8 00 00 00 00       	mov    $0x0,%eax
    3205:	e8 1e fe ff ff       	call   3028 <skip>
    320a:	48 85 c0             	test   %rax,%rax
    320d:	74 5f                	je     326e <read_line+0x78>
    320f:	8b 1d ef 48 00 00    	mov    0x48ef(%rip),%ebx        # 7b04 <num_input_strings>
    3215:	48 63 c3             	movslq %ebx,%rax
    3218:	48 8d 04 80          	lea    (%rax,%rax,4),%rax
    321c:	48 8d 14 80          	lea    (%rax,%rax,4),%rdx
    3220:	48 8d 05 f9 48 00 00 	lea    0x48f9(%rip),%rax        # 7b20 <input_strings>
    3227:	48 8d 2c 90          	lea    (%rax,%rdx,4),%rbp
    322b:	48 89 ef             	mov    %rbp,%rdi
    322e:	e8 3d f0 ff ff       	call   2270 <strlen@plt>
    3233:	83 f8 62             	cmp    $0x62,%eax
    3236:	0f 8f aa 00 00 00    	jg     32e6 <read_line+0xf0>
    323c:	83 e8 01             	sub    $0x1,%eax
    323f:	48 98                	cltq   
    3241:	48 63 d3             	movslq %ebx,%rdx
    3244:	48 8d 14 92          	lea    (%rdx,%rdx,4),%rdx
    3248:	48 8d 0c 92          	lea    (%rdx,%rdx,4),%rcx
    324c:	48 8d 15 cd 48 00 00 	lea    0x48cd(%rip),%rdx        # 7b20 <input_strings>
    3253:	48 8d 14 8a          	lea    (%rdx,%rcx,4),%rdx
    3257:	c6 04 02 00          	movb   $0x0,(%rdx,%rax,1)
    325b:	83 c3 01             	add    $0x1,%ebx
    325e:	89 1d a0 48 00 00    	mov    %ebx,0x48a0(%rip)        # 7b04 <num_input_strings>
    3264:	48 89 e8             	mov    %rbp,%rax
    3267:	48 83 c4 08          	add    $0x8,%rsp
    326b:	5b                   	pop    %rbx
    326c:	5d                   	pop    %rbp
    326d:	c3                   	ret    
    326e:	48 8b 05 fb 47 00 00 	mov    0x47fb(%rip),%rax        # 7a70 <stdin@GLIBC_2.2.5>
    3275:	48 39 05 14 48 00 00 	cmp    %rax,0x4814(%rip)        # 7a90 <infile>
    327c:	74 1b                	je     3299 <read_line+0xa3>
    327e:	48 8d 3d cc 1a 00 00 	lea    0x1acc(%rip),%rdi        # 4d51 <array.0+0xbb1>
    3285:	e8 86 ef ff ff       	call   2210 <getenv@plt>
    328a:	48 85 c0             	test   %rax,%rax
    328d:	74 20                	je     32af <read_line+0xb9>
    328f:	bf 00 00 00 00       	mov    $0x0,%edi
    3294:	e8 d7 f0 ff ff       	call   2370 <exit@plt>
    3299:	48 8d 3d 93 1a 00 00 	lea    0x1a93(%rip),%rdi        # 4d33 <array.0+0xb93>
    32a0:	e8 ab ef ff ff       	call   2250 <puts@plt>
    32a5:	bf 08 00 00 00       	mov    $0x8,%edi
    32aa:	e8 c1 f0 ff ff       	call   2370 <exit@plt>
    32af:	48 8b 05 ba 47 00 00 	mov    0x47ba(%rip),%rax        # 7a70 <stdin@GLIBC_2.2.5>
    32b6:	48 89 05 d3 47 00 00 	mov    %rax,0x47d3(%rip)        # 7a90 <infile>
    32bd:	b8 00 00 00 00       	mov    $0x0,%eax
    32c2:	e8 61 fd ff ff       	call   3028 <skip>
    32c7:	48 85 c0             	test   %rax,%rax
    32ca:	0f 85 3f ff ff ff    	jne    320f <read_line+0x19>
    32d0:	48 8d 3d 5c 1a 00 00 	lea    0x1a5c(%rip),%rdi        # 4d33 <array.0+0xb93>
    32d7:	e8 74 ef ff ff       	call   2250 <puts@plt>
    32dc:	bf 00 00 00 00       	mov    $0x0,%edi
    32e1:	e8 8a f0 ff ff       	call   2370 <exit@plt>
    32e6:	48 8d 3d 6f 1a 00 00 	lea    0x1a6f(%rip),%rdi        # 4d5c <array.0+0xbbc>
    32ed:	e8 5e ef ff ff       	call   2250 <puts@plt>
    32f2:	8b 05 0c 48 00 00    	mov    0x480c(%rip),%eax        # 7b04 <num_input_strings>
    32f8:	8d 50 01             	lea    0x1(%rax),%edx
    32fb:	89 15 03 48 00 00    	mov    %edx,0x4803(%rip)        # 7b04 <num_input_strings>
    3301:	48 98                	cltq   
    3303:	48 6b c0 64          	imul   $0x64,%rax,%rax
    3307:	48 8d 15 12 48 00 00 	lea    0x4812(%rip),%rdx        # 7b20 <input_strings>
    330e:	48 be 2a 2a 2a 74 72 	movabs $0x636e7572742a2a2a,%rsi
    3315:	75 6e 63 
    3318:	48 bf 61 74 65 64 2a 	movabs $0x2a2a2a64657461,%rdi
    331f:	2a 2a 00 
    3322:	48 89 34 02          	mov    %rsi,(%rdx,%rax,1)
    3326:	48 89 7c 02 08       	mov    %rdi,0x8(%rdx,%rax,1)
    332b:	e8 3f fe ff ff       	call   316f <explode_bomb>

0000000000003330 <phase_defused>:
    3330:	f3 0f 1e fa          	endbr64 
    3334:	48 81 ec 88 00 00 00 	sub    $0x88,%rsp
    333b:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    3342:	00 00 
    3344:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
    3349:	31 c0                	xor    %eax,%eax
    334b:	bf 01 00 00 00       	mov    $0x1,%edi
    3350:	e8 27 fd ff ff       	call   307c <send_msg>
    3355:	83 3d a8 47 00 00 06 	cmpl   $0x6,0x47a8(%rip)        # 7b04 <num_input_strings>
    335c:	74 1c                	je     337a <phase_defused+0x4a>
    335e:	48 8b 44 24 78       	mov    0x78(%rsp),%rax
    3363:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    336a:	00 00 
    336c:	0f 85 87 00 00 00    	jne    33f9 <phase_defused+0xc9>
    3372:	48 81 c4 88 00 00 00 	add    $0x88,%rsp
    3379:	c3                   	ret    
    337a:	48 8d 4c 24 0c       	lea    0xc(%rsp),%rcx
    337f:	48 8d 54 24 08       	lea    0x8(%rsp),%rdx
    3384:	4c 8d 44 24 10       	lea    0x10(%rsp),%r8
    3389:	48 8d 35 e7 19 00 00 	lea    0x19e7(%rip),%rsi        # 4d77 <array.0+0xbd7>
    3390:	48 8d 3d b5 48 00 00 	lea    0x48b5(%rip),%rdi        # 7c4c <input_strings+0x12c>
    3397:	b8 00 00 00 00       	mov    $0x0,%eax
    339c:	e8 8f ef ff ff       	call   2330 <__isoc99_sscanf@plt>
    33a1:	83 f8 03             	cmp    $0x3,%eax
    33a4:	74 1a                	je     33c0 <phase_defused+0x90>
    33a6:	48 8d 3d 8b 18 00 00 	lea    0x188b(%rip),%rdi        # 4c38 <array.0+0xa98>
    33ad:	e8 9e ee ff ff       	call   2250 <puts@plt>
    33b2:	48 8d 3d af 18 00 00 	lea    0x18af(%rip),%rdi        # 4c68 <array.0+0xac8>
    33b9:	e8 92 ee ff ff       	call   2250 <puts@plt>
    33be:	eb 9e                	jmp    335e <phase_defused+0x2e>
    33c0:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
    33c5:	48 8d 35 b4 19 00 00 	lea    0x19b4(%rip),%rsi        # 4d80 <array.0+0xbe0>
    33cc:	e8 47 f9 ff ff       	call   2d18 <strings_not_equal>
    33d1:	85 c0                	test   %eax,%eax
    33d3:	75 d1                	jne    33a6 <phase_defused+0x76>
    33d5:	48 8d 3d fc 17 00 00 	lea    0x17fc(%rip),%rdi        # 4bd8 <array.0+0xa38>
    33dc:	e8 6f ee ff ff       	call   2250 <puts@plt>
    33e1:	48 8d 3d 18 18 00 00 	lea    0x1818(%rip),%rdi        # 4c00 <array.0+0xa60>
    33e8:	e8 63 ee ff ff       	call   2250 <puts@plt>
    33ed:	b8 00 00 00 00       	mov    $0x0,%eax
    33f2:	e8 5e f7 ff ff       	call   2b55 <secret_phase>
    33f7:	eb ad                	jmp    33a6 <phase_defused+0x76>
    33f9:	e8 82 ee ff ff       	call   2280 <__stack_chk_fail@plt>

00000000000033fe <sigalrm_handler>:
    33fe:	f3 0f 1e fa          	endbr64 
    3402:	50                   	push   %rax
    3403:	58                   	pop    %rax
    3404:	48 83 ec 08          	sub    $0x8,%rsp
    3408:	b9 00 00 00 00       	mov    $0x0,%ecx
    340d:	48 8d 15 84 1c 00 00 	lea    0x1c84(%rip),%rdx        # 5098 <array.0+0xef8>
    3414:	be 01 00 00 00       	mov    $0x1,%esi
    3419:	48 8b 3d 60 46 00 00 	mov    0x4660(%rip),%rdi        # 7a80 <stderr@GLIBC_2.2.5>
    3420:	b8 00 00 00 00       	mov    $0x0,%eax
    3425:	e8 66 ef ff ff       	call   2390 <__fprintf_chk@plt>
    342a:	bf 01 00 00 00       	mov    $0x1,%edi
    342f:	e8 3c ef ff ff       	call   2370 <exit@plt>

0000000000003434 <rio_readlineb>:
    3434:	41 56                	push   %r14
    3436:	41 55                	push   %r13
    3438:	41 54                	push   %r12
    343a:	55                   	push   %rbp
    343b:	53                   	push   %rbx
    343c:	49 89 f4             	mov    %rsi,%r12
    343f:	48 83 fa 01          	cmp    $0x1,%rdx
    3443:	0f 86 92 00 00 00    	jbe    34db <rio_readlineb+0xa7>
    3449:	48 89 fb             	mov    %rdi,%rbx
    344c:	4c 8d 74 16 ff       	lea    -0x1(%rsi,%rdx,1),%r14
    3451:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    3457:	48 8d 6f 10          	lea    0x10(%rdi),%rbp
    345b:	eb 56                	jmp    34b3 <rio_readlineb+0x7f>
    345d:	e8 ce ed ff ff       	call   2230 <__errno_location@plt>
    3462:	83 38 04             	cmpl   $0x4,(%rax)
    3465:	75 55                	jne    34bc <rio_readlineb+0x88>
    3467:	ba 00 20 00 00       	mov    $0x2000,%edx
    346c:	48 89 ee             	mov    %rbp,%rsi
    346f:	8b 3b                	mov    (%rbx),%edi
    3471:	e8 3a ee ff ff       	call   22b0 <read@plt>
    3476:	89 c2                	mov    %eax,%edx
    3478:	89 43 04             	mov    %eax,0x4(%rbx)
    347b:	85 c0                	test   %eax,%eax
    347d:	78 de                	js     345d <rio_readlineb+0x29>
    347f:	85 c0                	test   %eax,%eax
    3481:	74 42                	je     34c5 <rio_readlineb+0x91>
    3483:	48 89 6b 08          	mov    %rbp,0x8(%rbx)
    3487:	48 8b 43 08          	mov    0x8(%rbx),%rax
    348b:	0f b6 08             	movzbl (%rax),%ecx
    348e:	48 83 c0 01          	add    $0x1,%rax
    3492:	48 89 43 08          	mov    %rax,0x8(%rbx)
    3496:	83 ea 01             	sub    $0x1,%edx
    3499:	89 53 04             	mov    %edx,0x4(%rbx)
    349c:	49 83 c4 01          	add    $0x1,%r12
    34a0:	41 88 4c 24 ff       	mov    %cl,-0x1(%r12)
    34a5:	80 f9 0a             	cmp    $0xa,%cl
    34a8:	74 3c                	je     34e6 <rio_readlineb+0xb2>
    34aa:	41 83 c5 01          	add    $0x1,%r13d
    34ae:	4d 39 f4             	cmp    %r14,%r12
    34b1:	74 30                	je     34e3 <rio_readlineb+0xaf>
    34b3:	8b 53 04             	mov    0x4(%rbx),%edx
    34b6:	85 d2                	test   %edx,%edx
    34b8:	7e ad                	jle    3467 <rio_readlineb+0x33>
    34ba:	eb cb                	jmp    3487 <rio_readlineb+0x53>
    34bc:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
    34c3:	eb 05                	jmp    34ca <rio_readlineb+0x96>
    34c5:	b8 00 00 00 00       	mov    $0x0,%eax
    34ca:	85 c0                	test   %eax,%eax
    34cc:	75 29                	jne    34f7 <rio_readlineb+0xc3>
    34ce:	b8 00 00 00 00       	mov    $0x0,%eax
    34d3:	41 83 fd 01          	cmp    $0x1,%r13d
    34d7:	75 0d                	jne    34e6 <rio_readlineb+0xb2>
    34d9:	eb 13                	jmp    34ee <rio_readlineb+0xba>
    34db:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    34e1:	eb 03                	jmp    34e6 <rio_readlineb+0xb2>
    34e3:	4d 89 f4             	mov    %r14,%r12
    34e6:	41 c6 04 24 00       	movb   $0x0,(%r12)
    34eb:	49 63 c5             	movslq %r13d,%rax
    34ee:	5b                   	pop    %rbx
    34ef:	5d                   	pop    %rbp
    34f0:	41 5c                	pop    %r12
    34f2:	41 5d                	pop    %r13
    34f4:	41 5e                	pop    %r14
    34f6:	c3                   	ret    
    34f7:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
    34fe:	eb ee                	jmp    34ee <rio_readlineb+0xba>

0000000000003500 <submitr>:
    3500:	f3 0f 1e fa          	endbr64 
    3504:	41 57                	push   %r15
    3506:	41 56                	push   %r14
    3508:	41 55                	push   %r13
    350a:	41 54                	push   %r12
    350c:	55                   	push   %rbp
    350d:	53                   	push   %rbx
    350e:	4c 8d 9c 24 00 60 ff 	lea    -0xa000(%rsp),%r11
    3515:	ff 
    3516:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    351d:	48 83 0c 24 00       	orq    $0x0,(%rsp)
    3522:	4c 39 dc             	cmp    %r11,%rsp
    3525:	75 ef                	jne    3516 <submitr+0x16>
    3527:	48 83 ec 78          	sub    $0x78,%rsp
    352b:	49 89 fd             	mov    %rdi,%r13
    352e:	89 f5                	mov    %esi,%ebp
    3530:	48 89 54 24 08       	mov    %rdx,0x8(%rsp)
    3535:	48 89 4c 24 10       	mov    %rcx,0x10(%rsp)
    353a:	4c 89 44 24 20       	mov    %r8,0x20(%rsp)
    353f:	4c 89 4c 24 18       	mov    %r9,0x18(%rsp)
    3544:	48 8b 9c 24 b0 a0 00 	mov    0xa0b0(%rsp),%rbx
    354b:	00 
    354c:	4c 8b bc 24 b8 a0 00 	mov    0xa0b8(%rsp),%r15
    3553:	00 
    3554:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    355b:	00 00 
    355d:	48 89 84 24 68 a0 00 	mov    %rax,0xa068(%rsp)
    3564:	00 
    3565:	31 c0                	xor    %eax,%eax
    3567:	c7 44 24 3c 00 00 00 	movl   $0x0,0x3c(%rsp)
    356e:	00 
    356f:	ba 00 00 00 00       	mov    $0x0,%edx
    3574:	be 01 00 00 00       	mov    $0x1,%esi
    3579:	bf 02 00 00 00       	mov    $0x2,%edi
    357e:	e8 4d ee ff ff       	call   23d0 <socket@plt>
    3583:	85 c0                	test   %eax,%eax
    3585:	0f 88 12 01 00 00    	js     369d <submitr+0x19d>
    358b:	41 89 c4             	mov    %eax,%r12d
    358e:	4c 89 ef             	mov    %r13,%rdi
    3591:	e8 5a ed ff ff       	call   22f0 <gethostbyname@plt>
    3596:	48 85 c0             	test   %rax,%rax
    3599:	0f 84 4e 01 00 00    	je     36ed <submitr+0x1ed>
    359f:	4c 8d 6c 24 40       	lea    0x40(%rsp),%r13
    35a4:	48 c7 44 24 40 00 00 	movq   $0x0,0x40(%rsp)
    35ab:	00 00 
    35ad:	48 c7 44 24 48 00 00 	movq   $0x0,0x48(%rsp)
    35b4:	00 00 
    35b6:	66 c7 44 24 40 02 00 	movw   $0x2,0x40(%rsp)
    35bd:	48 63 50 14          	movslq 0x14(%rax),%rdx
    35c1:	48 8b 40 18          	mov    0x18(%rax),%rax
    35c5:	48 8d 7c 24 44       	lea    0x44(%rsp),%rdi
    35ca:	b9 0c 00 00 00       	mov    $0xc,%ecx
    35cf:	48 8b 30             	mov    (%rax),%rsi
    35d2:	e8 29 ed ff ff       	call   2300 <__memmove_chk@plt>
    35d7:	66 c1 c5 08          	rol    $0x8,%bp
    35db:	66 89 6c 24 42       	mov    %bp,0x42(%rsp)
    35e0:	ba 10 00 00 00       	mov    $0x10,%edx
    35e5:	4c 89 ee             	mov    %r13,%rsi
    35e8:	44 89 e7             	mov    %r12d,%edi
    35eb:	e8 90 ed ff ff       	call   2380 <connect@plt>
    35f0:	85 c0                	test   %eax,%eax
    35f2:	0f 88 60 01 00 00    	js     3758 <submitr+0x258>
    35f8:	48 89 df             	mov    %rbx,%rdi
    35fb:	e8 70 ec ff ff       	call   2270 <strlen@plt>
    3600:	48 89 c5             	mov    %rax,%rbp
    3603:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
    3608:	e8 63 ec ff ff       	call   2270 <strlen@plt>
    360d:	49 89 c6             	mov    %rax,%r14
    3610:	48 8b 7c 24 10       	mov    0x10(%rsp),%rdi
    3615:	e8 56 ec ff ff       	call   2270 <strlen@plt>
    361a:	49 89 c5             	mov    %rax,%r13
    361d:	48 8b 7c 24 18       	mov    0x18(%rsp),%rdi
    3622:	e8 49 ec ff ff       	call   2270 <strlen@plt>
    3627:	48 89 c2             	mov    %rax,%rdx
    362a:	4b 8d 84 2e 80 00 00 	lea    0x80(%r14,%r13,1),%rax
    3631:	00 
    3632:	48 01 d0             	add    %rdx,%rax
    3635:	48 8d 54 6d 00       	lea    0x0(%rbp,%rbp,2),%rdx
    363a:	48 01 d0             	add    %rdx,%rax
    363d:	48 3d 00 20 00 00    	cmp    $0x2000,%rax
    3643:	0f 87 6c 01 00 00    	ja     37b5 <submitr+0x2b5>
    3649:	48 8d 94 24 60 40 00 	lea    0x4060(%rsp),%rdx
    3650:	00 
    3651:	b9 00 04 00 00       	mov    $0x400,%ecx
    3656:	b8 00 00 00 00       	mov    $0x0,%eax
    365b:	48 89 d7             	mov    %rdx,%rdi
    365e:	f3 48 ab             	rep stos %rax,%es:(%rdi)
    3661:	48 89 df             	mov    %rbx,%rdi
    3664:	e8 07 ec ff ff       	call   2270 <strlen@plt>
    3669:	85 c0                	test   %eax,%eax
    366b:	0f 84 07 05 00 00    	je     3b78 <submitr+0x678>
    3671:	8d 40 ff             	lea    -0x1(%rax),%eax
    3674:	4c 8d 6c 03 01       	lea    0x1(%rbx,%rax,1),%r13
    3679:	48 8d ac 24 60 40 00 	lea    0x4060(%rsp),%rbp
    3680:	00 
    3681:	48 8d 84 24 60 80 00 	lea    0x8060(%rsp),%rax
    3688:	00 
    3689:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
    368e:	49 be d9 ff 00 00 00 	movabs $0x2000000000ffd9,%r14
    3695:	00 20 00 
    3698:	e9 a6 01 00 00       	jmp    3843 <submitr+0x343>
    369d:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    36a4:	3a 20 43 
    36a7:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    36ae:	20 75 6e 
    36b1:	49 89 07             	mov    %rax,(%r15)
    36b4:	49 89 57 08          	mov    %rdx,0x8(%r15)
    36b8:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    36bf:	74 6f 20 
    36c2:	48 ba 63 72 65 61 74 	movabs $0x7320657461657263,%rdx
    36c9:	65 20 73 
    36cc:	49 89 47 10          	mov    %rax,0x10(%r15)
    36d0:	49 89 57 18          	mov    %rdx,0x18(%r15)
    36d4:	41 c7 47 20 6f 63 6b 	movl   $0x656b636f,0x20(%r15)
    36db:	65 
    36dc:	66 41 c7 47 24 74 00 	movw   $0x74,0x24(%r15)
    36e3:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    36e8:	e9 03 03 00 00       	jmp    39f0 <submitr+0x4f0>
    36ed:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
    36f4:	3a 20 44 
    36f7:	48 ba 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rdx
    36fe:	20 75 6e 
    3701:	49 89 07             	mov    %rax,(%r15)
    3704:	49 89 57 08          	mov    %rdx,0x8(%r15)
    3708:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    370f:	74 6f 20 
    3712:	48 ba 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rdx
    3719:	76 65 20 
    371c:	49 89 47 10          	mov    %rax,0x10(%r15)
    3720:	49 89 57 18          	mov    %rdx,0x18(%r15)
    3724:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
    372b:	72 20 61 
    372e:	49 89 47 20          	mov    %rax,0x20(%r15)
    3732:	41 c7 47 28 64 64 72 	movl   $0x65726464,0x28(%r15)
    3739:	65 
    373a:	66 41 c7 47 2c 73 73 	movw   $0x7373,0x2c(%r15)
    3741:	41 c6 47 2e 00       	movb   $0x0,0x2e(%r15)
    3746:	44 89 e7             	mov    %r12d,%edi
    3749:	e8 52 eb ff ff       	call   22a0 <close@plt>
    374e:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    3753:	e9 98 02 00 00       	jmp    39f0 <submitr+0x4f0>
    3758:	48 b8 45 72 72 6f 72 	movabs $0x55203a726f727245,%rax
    375f:	3a 20 55 
    3762:	48 ba 6e 61 62 6c 65 	movabs $0x6f7420656c62616e,%rdx
    3769:	20 74 6f 
    376c:	49 89 07             	mov    %rax,(%r15)
    376f:	49 89 57 08          	mov    %rdx,0x8(%r15)
    3773:	48 b8 20 63 6f 6e 6e 	movabs $0x7463656e6e6f6320,%rax
    377a:	65 63 74 
    377d:	48 ba 20 74 6f 20 74 	movabs $0x20656874206f7420,%rdx
    3784:	68 65 20 
    3787:	49 89 47 10          	mov    %rax,0x10(%r15)
    378b:	49 89 57 18          	mov    %rdx,0x18(%r15)
    378f:	41 c7 47 20 73 65 72 	movl   $0x76726573,0x20(%r15)
    3796:	76 
    3797:	66 41 c7 47 24 65 72 	movw   $0x7265,0x24(%r15)
    379e:	41 c6 47 26 00       	movb   $0x0,0x26(%r15)
    37a3:	44 89 e7             	mov    %r12d,%edi
    37a6:	e8 f5 ea ff ff       	call   22a0 <close@plt>
    37ab:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    37b0:	e9 3b 02 00 00       	jmp    39f0 <submitr+0x4f0>
    37b5:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
    37bc:	3a 20 52 
    37bf:	48 ba 65 73 75 6c 74 	movabs $0x747320746c757365,%rdx
    37c6:	20 73 74 
    37c9:	49 89 07             	mov    %rax,(%r15)
    37cc:	49 89 57 08          	mov    %rdx,0x8(%r15)
    37d0:	48 b8 72 69 6e 67 20 	movabs $0x6f6f7420676e6972,%rax
    37d7:	74 6f 6f 
    37da:	48 ba 20 6c 61 72 67 	movabs $0x202e656772616c20,%rdx
    37e1:	65 2e 20 
    37e4:	49 89 47 10          	mov    %rax,0x10(%r15)
    37e8:	49 89 57 18          	mov    %rdx,0x18(%r15)
    37ec:	48 b8 49 6e 63 72 65 	movabs $0x6573616572636e49,%rax
    37f3:	61 73 65 
    37f6:	48 ba 20 53 55 42 4d 	movabs $0x5254494d42555320,%rdx
    37fd:	49 54 52 
    3800:	49 89 47 20          	mov    %rax,0x20(%r15)
    3804:	49 89 57 28          	mov    %rdx,0x28(%r15)
    3808:	48 b8 5f 4d 41 58 42 	movabs $0x46554258414d5f,%rax
    380f:	55 46 00 
    3812:	49 89 47 30          	mov    %rax,0x30(%r15)
    3816:	44 89 e7             	mov    %r12d,%edi
    3819:	e8 82 ea ff ff       	call   22a0 <close@plt>
    381e:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    3823:	e9 c8 01 00 00       	jmp    39f0 <submitr+0x4f0>
    3828:	49 0f a3 c6          	bt     %rax,%r14
    382c:	73 21                	jae    384f <submitr+0x34f>
    382e:	44 88 45 00          	mov    %r8b,0x0(%rbp)
    3832:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
    3836:	48 83 c3 01          	add    $0x1,%rbx
    383a:	4c 39 eb             	cmp    %r13,%rbx
    383d:	0f 84 35 03 00 00    	je     3b78 <submitr+0x678>
    3843:	44 0f b6 03          	movzbl (%rbx),%r8d
    3847:	41 8d 40 d6          	lea    -0x2a(%r8),%eax
    384b:	3c 35                	cmp    $0x35,%al
    384d:	76 d9                	jbe    3828 <submitr+0x328>
    384f:	44 89 c0             	mov    %r8d,%eax
    3852:	83 e0 df             	and    $0xffffffdf,%eax
    3855:	83 e8 41             	sub    $0x41,%eax
    3858:	3c 19                	cmp    $0x19,%al
    385a:	76 d2                	jbe    382e <submitr+0x32e>
    385c:	41 80 f8 20          	cmp    $0x20,%r8b
    3860:	74 60                	je     38c2 <submitr+0x3c2>
    3862:	41 8d 40 e0          	lea    -0x20(%r8),%eax
    3866:	3c 5f                	cmp    $0x5f,%al
    3868:	76 0a                	jbe    3874 <submitr+0x374>
    386a:	41 80 f8 09          	cmp    $0x9,%r8b
    386e:	0f 85 77 02 00 00    	jne    3aeb <submitr+0x5eb>
    3874:	45 0f b6 c0          	movzbl %r8b,%r8d
    3878:	48 8d 0d ef 18 00 00 	lea    0x18ef(%rip),%rcx        # 516e <array.0+0xfce>
    387f:	ba 08 00 00 00       	mov    $0x8,%edx
    3884:	be 01 00 00 00       	mov    $0x1,%esi
    3889:	48 8b 7c 24 28       	mov    0x28(%rsp),%rdi
    388e:	b8 00 00 00 00       	mov    $0x0,%eax
    3893:	e8 28 eb ff ff       	call   23c0 <__sprintf_chk@plt>
    3898:	0f b6 84 24 60 80 00 	movzbl 0x8060(%rsp),%eax
    389f:	00 
    38a0:	88 45 00             	mov    %al,0x0(%rbp)
    38a3:	0f b6 84 24 61 80 00 	movzbl 0x8061(%rsp),%eax
    38aa:	00 
    38ab:	88 45 01             	mov    %al,0x1(%rbp)
    38ae:	0f b6 84 24 62 80 00 	movzbl 0x8062(%rsp),%eax
    38b5:	00 
    38b6:	88 45 02             	mov    %al,0x2(%rbp)
    38b9:	48 8d 6d 03          	lea    0x3(%rbp),%rbp
    38bd:	e9 74 ff ff ff       	jmp    3836 <submitr+0x336>
    38c2:	c6 45 00 2b          	movb   $0x2b,0x0(%rbp)
    38c6:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
    38ca:	e9 67 ff ff ff       	jmp    3836 <submitr+0x336>
    38cf:	48 01 c5             	add    %rax,%rbp
    38d2:	48 29 c3             	sub    %rax,%rbx
    38d5:	0f 84 08 03 00 00    	je     3be3 <submitr+0x6e3>
    38db:	48 89 da             	mov    %rbx,%rdx
    38de:	48 89 ee             	mov    %rbp,%rsi
    38e1:	44 89 e7             	mov    %r12d,%edi
    38e4:	e8 77 e9 ff ff       	call   2260 <write@plt>
    38e9:	48 85 c0             	test   %rax,%rax
    38ec:	7f e1                	jg     38cf <submitr+0x3cf>
    38ee:	e8 3d e9 ff ff       	call   2230 <__errno_location@plt>
    38f3:	83 38 04             	cmpl   $0x4,(%rax)
    38f6:	0f 85 90 01 00 00    	jne    3a8c <submitr+0x58c>
    38fc:	4c 89 e8             	mov    %r13,%rax
    38ff:	eb ce                	jmp    38cf <submitr+0x3cf>
    3901:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    3908:	3a 20 43 
    390b:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    3912:	20 75 6e 
    3915:	49 89 07             	mov    %rax,(%r15)
    3918:	49 89 57 08          	mov    %rdx,0x8(%r15)
    391c:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    3923:	74 6f 20 
    3926:	48 ba 72 65 61 64 20 	movabs $0x7269662064616572,%rdx
    392d:	66 69 72 
    3930:	49 89 47 10          	mov    %rax,0x10(%r15)
    3934:	49 89 57 18          	mov    %rdx,0x18(%r15)
    3938:	48 b8 73 74 20 68 65 	movabs $0x6564616568207473,%rax
    393f:	61 64 65 
    3942:	48 ba 72 20 66 72 6f 	movabs $0x73206d6f72662072,%rdx
    3949:	6d 20 73 
    394c:	49 89 47 20          	mov    %rax,0x20(%r15)
    3950:	49 89 57 28          	mov    %rdx,0x28(%r15)
    3954:	41 c7 47 30 65 72 76 	movl   $0x65767265,0x30(%r15)
    395b:	65 
    395c:	66 41 c7 47 34 72 00 	movw   $0x72,0x34(%r15)
    3963:	44 89 e7             	mov    %r12d,%edi
    3966:	e8 35 e9 ff ff       	call   22a0 <close@plt>
    396b:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    3970:	eb 7e                	jmp    39f0 <submitr+0x4f0>
    3972:	4c 8d 8c 24 60 80 00 	lea    0x8060(%rsp),%r9
    3979:	00 
    397a:	48 8d 0d 3f 17 00 00 	lea    0x173f(%rip),%rcx        # 50c0 <array.0+0xf20>
    3981:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    3988:	be 01 00 00 00       	mov    $0x1,%esi
    398d:	4c 89 ff             	mov    %r15,%rdi
    3990:	b8 00 00 00 00       	mov    $0x0,%eax
    3995:	e8 26 ea ff ff       	call   23c0 <__sprintf_chk@plt>
    399a:	44 89 e7             	mov    %r12d,%edi
    399d:	e8 fe e8 ff ff       	call   22a0 <close@plt>
    39a2:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    39a7:	eb 47                	jmp    39f0 <submitr+0x4f0>
    39a9:	48 8d b4 24 60 20 00 	lea    0x2060(%rsp),%rsi
    39b0:	00 
    39b1:	48 8d 7c 24 50       	lea    0x50(%rsp),%rdi
    39b6:	ba 00 20 00 00       	mov    $0x2000,%edx
    39bb:	e8 74 fa ff ff       	call   3434 <rio_readlineb>
    39c0:	48 85 c0             	test   %rax,%rax
    39c3:	7e 54                	jle    3a19 <submitr+0x519>
    39c5:	48 8d b4 24 60 20 00 	lea    0x2060(%rsp),%rsi
    39cc:	00 
    39cd:	4c 89 ff             	mov    %r15,%rdi
    39d0:	e8 6b e8 ff ff       	call   2240 <strcpy@plt>
    39d5:	44 89 e7             	mov    %r12d,%edi
    39d8:	e8 c3 e8 ff ff       	call   22a0 <close@plt>
    39dd:	48 8d 35 a5 17 00 00 	lea    0x17a5(%rip),%rsi        # 5189 <array.0+0xfe9>
    39e4:	4c 89 ff             	mov    %r15,%rdi
    39e7:	e8 e4 e8 ff ff       	call   22d0 <strcmp@plt>
    39ec:	f7 d8                	neg    %eax
    39ee:	19 c0                	sbb    %eax,%eax
    39f0:	48 8b 94 24 68 a0 00 	mov    0xa068(%rsp),%rdx
    39f7:	00 
    39f8:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    39ff:	00 00 
    3a01:	0f 85 f8 02 00 00    	jne    3cff <submitr+0x7ff>
    3a07:	48 81 c4 78 a0 00 00 	add    $0xa078,%rsp
    3a0e:	5b                   	pop    %rbx
    3a0f:	5d                   	pop    %rbp
    3a10:	41 5c                	pop    %r12
    3a12:	41 5d                	pop    %r13
    3a14:	41 5e                	pop    %r14
    3a16:	41 5f                	pop    %r15
    3a18:	c3                   	ret    
    3a19:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    3a20:	3a 20 43 
    3a23:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    3a2a:	20 75 6e 
    3a2d:	49 89 07             	mov    %rax,(%r15)
    3a30:	49 89 57 08          	mov    %rdx,0x8(%r15)
    3a34:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    3a3b:	74 6f 20 
    3a3e:	48 ba 72 65 61 64 20 	movabs $0x6174732064616572,%rdx
    3a45:	73 74 61 
    3a48:	49 89 47 10          	mov    %rax,0x10(%r15)
    3a4c:	49 89 57 18          	mov    %rdx,0x18(%r15)
    3a50:	48 b8 74 75 73 20 6d 	movabs $0x7373656d20737574,%rax
    3a57:	65 73 73 
    3a5a:	48 ba 61 67 65 20 66 	movabs $0x6d6f726620656761,%rdx
    3a61:	72 6f 6d 
    3a64:	49 89 47 20          	mov    %rax,0x20(%r15)
    3a68:	49 89 57 28          	mov    %rdx,0x28(%r15)
    3a6c:	48 b8 20 73 65 72 76 	movabs $0x72657672657320,%rax
    3a73:	65 72 00 
    3a76:	49 89 47 30          	mov    %rax,0x30(%r15)
    3a7a:	44 89 e7             	mov    %r12d,%edi
    3a7d:	e8 1e e8 ff ff       	call   22a0 <close@plt>
    3a82:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    3a87:	e9 64 ff ff ff       	jmp    39f0 <submitr+0x4f0>
    3a8c:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    3a93:	3a 20 43 
    3a96:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    3a9d:	20 75 6e 
    3aa0:	49 89 07             	mov    %rax,(%r15)
    3aa3:	49 89 57 08          	mov    %rdx,0x8(%r15)
    3aa7:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    3aae:	74 6f 20 
    3ab1:	48 ba 77 72 69 74 65 	movabs $0x6f74206574697277,%rdx
    3ab8:	20 74 6f 
    3abb:	49 89 47 10          	mov    %rax,0x10(%r15)
    3abf:	49 89 57 18          	mov    %rdx,0x18(%r15)
    3ac3:	48 b8 20 74 68 65 20 	movabs $0x7265732065687420,%rax
    3aca:	73 65 72 
    3acd:	49 89 47 20          	mov    %rax,0x20(%r15)
    3ad1:	41 c7 47 28 76 65 72 	movl   $0x726576,0x28(%r15)
    3ad8:	00 
    3ad9:	44 89 e7             	mov    %r12d,%edi
    3adc:	e8 bf e7 ff ff       	call   22a0 <close@plt>
    3ae1:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    3ae6:	e9 05 ff ff ff       	jmp    39f0 <submitr+0x4f0>
    3aeb:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
    3af2:	3a 20 52 
    3af5:	48 ba 65 73 75 6c 74 	movabs $0x747320746c757365,%rdx
    3afc:	20 73 74 
    3aff:	49 89 07             	mov    %rax,(%r15)
    3b02:	49 89 57 08          	mov    %rdx,0x8(%r15)
    3b06:	48 b8 72 69 6e 67 20 	movabs $0x6e6f6320676e6972,%rax
    3b0d:	63 6f 6e 
    3b10:	48 ba 74 61 69 6e 73 	movabs $0x6e6120736e696174,%rdx
    3b17:	20 61 6e 
    3b1a:	49 89 47 10          	mov    %rax,0x10(%r15)
    3b1e:	49 89 57 18          	mov    %rdx,0x18(%r15)
    3b22:	48 b8 20 69 6c 6c 65 	movabs $0x6c6167656c6c6920,%rax
    3b29:	67 61 6c 
    3b2c:	48 ba 20 6f 72 20 75 	movabs $0x72706e7520726f20,%rdx
    3b33:	6e 70 72 
    3b36:	49 89 47 20          	mov    %rax,0x20(%r15)
    3b3a:	49 89 57 28          	mov    %rdx,0x28(%r15)
    3b3e:	48 b8 69 6e 74 61 62 	movabs $0x20656c6261746e69,%rax
    3b45:	6c 65 20 
    3b48:	48 ba 63 68 61 72 61 	movabs $0x6574636172616863,%rdx
    3b4f:	63 74 65 
    3b52:	49 89 47 30          	mov    %rax,0x30(%r15)
    3b56:	49 89 57 38          	mov    %rdx,0x38(%r15)
    3b5a:	66 41 c7 47 40 72 2e 	movw   $0x2e72,0x40(%r15)
    3b61:	41 c6 47 42 00       	movb   $0x0,0x42(%r15)
    3b66:	44 89 e7             	mov    %r12d,%edi
    3b69:	e8 32 e7 ff ff       	call   22a0 <close@plt>
    3b6e:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    3b73:	e9 78 fe ff ff       	jmp    39f0 <submitr+0x4f0>
    3b78:	48 8d 9c 24 60 20 00 	lea    0x2060(%rsp),%rbx
    3b7f:	00 
    3b80:	48 83 ec 08          	sub    $0x8,%rsp
    3b84:	48 8d 84 24 68 40 00 	lea    0x4068(%rsp),%rax
    3b8b:	00 
    3b8c:	50                   	push   %rax
    3b8d:	ff 74 24 28          	push   0x28(%rsp)
    3b91:	ff 74 24 38          	push   0x38(%rsp)
    3b95:	4c 8b 4c 24 30       	mov    0x30(%rsp),%r9
    3b9a:	4c 8b 44 24 28       	mov    0x28(%rsp),%r8
    3b9f:	48 8d 0d 4a 15 00 00 	lea    0x154a(%rip),%rcx        # 50f0 <array.0+0xf50>
    3ba6:	ba 00 20 00 00       	mov    $0x2000,%edx
    3bab:	be 01 00 00 00       	mov    $0x1,%esi
    3bb0:	48 89 df             	mov    %rbx,%rdi
    3bb3:	b8 00 00 00 00       	mov    $0x0,%eax
    3bb8:	e8 03 e8 ff ff       	call   23c0 <__sprintf_chk@plt>
    3bbd:	48 83 c4 20          	add    $0x20,%rsp
    3bc1:	48 89 df             	mov    %rbx,%rdi
    3bc4:	e8 a7 e6 ff ff       	call   2270 <strlen@plt>
    3bc9:	48 89 c3             	mov    %rax,%rbx
    3bcc:	48 8d ac 24 60 20 00 	lea    0x2060(%rsp),%rbp
    3bd3:	00 
    3bd4:	41 bd 00 00 00 00    	mov    $0x0,%r13d
    3bda:	48 85 c0             	test   %rax,%rax
    3bdd:	0f 85 f8 fc ff ff    	jne    38db <submitr+0x3db>
    3be3:	44 89 64 24 50       	mov    %r12d,0x50(%rsp)
    3be8:	c7 44 24 54 00 00 00 	movl   $0x0,0x54(%rsp)
    3bef:	00 
    3bf0:	48 8d 7c 24 50       	lea    0x50(%rsp),%rdi
    3bf5:	48 8d 44 24 60       	lea    0x60(%rsp),%rax
    3bfa:	48 89 44 24 58       	mov    %rax,0x58(%rsp)
    3bff:	48 8d b4 24 60 20 00 	lea    0x2060(%rsp),%rsi
    3c06:	00 
    3c07:	ba 00 20 00 00       	mov    $0x2000,%edx
    3c0c:	e8 23 f8 ff ff       	call   3434 <rio_readlineb>
    3c11:	48 85 c0             	test   %rax,%rax
    3c14:	0f 8e e7 fc ff ff    	jle    3901 <submitr+0x401>
    3c1a:	48 8d 4c 24 3c       	lea    0x3c(%rsp),%rcx
    3c1f:	48 8d 94 24 60 60 00 	lea    0x6060(%rsp),%rdx
    3c26:	00 
    3c27:	48 8d bc 24 60 20 00 	lea    0x2060(%rsp),%rdi
    3c2e:	00 
    3c2f:	4c 8d 84 24 60 80 00 	lea    0x8060(%rsp),%r8
    3c36:	00 
    3c37:	48 8d 35 37 15 00 00 	lea    0x1537(%rip),%rsi        # 5175 <array.0+0xfd5>
    3c3e:	b8 00 00 00 00       	mov    $0x0,%eax
    3c43:	e8 e8 e6 ff ff       	call   2330 <__isoc99_sscanf@plt>
    3c48:	44 8b 44 24 3c       	mov    0x3c(%rsp),%r8d
    3c4d:	41 81 f8 c8 00 00 00 	cmp    $0xc8,%r8d
    3c54:	0f 85 18 fd ff ff    	jne    3972 <submitr+0x472>
    3c5a:	48 8d 1d 25 15 00 00 	lea    0x1525(%rip),%rbx        # 5186 <array.0+0xfe6>
    3c61:	48 8d bc 24 60 20 00 	lea    0x2060(%rsp),%rdi
    3c68:	00 
    3c69:	48 89 de             	mov    %rbx,%rsi
    3c6c:	e8 5f e6 ff ff       	call   22d0 <strcmp@plt>
    3c71:	85 c0                	test   %eax,%eax
    3c73:	0f 84 30 fd ff ff    	je     39a9 <submitr+0x4a9>
    3c79:	48 8d b4 24 60 20 00 	lea    0x2060(%rsp),%rsi
    3c80:	00 
    3c81:	48 8d 7c 24 50       	lea    0x50(%rsp),%rdi
    3c86:	ba 00 20 00 00       	mov    $0x2000,%edx
    3c8b:	e8 a4 f7 ff ff       	call   3434 <rio_readlineb>
    3c90:	48 85 c0             	test   %rax,%rax
    3c93:	7f cc                	jg     3c61 <submitr+0x761>
    3c95:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    3c9c:	3a 20 43 
    3c9f:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    3ca6:	20 75 6e 
    3ca9:	49 89 07             	mov    %rax,(%r15)
    3cac:	49 89 57 08          	mov    %rdx,0x8(%r15)
    3cb0:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    3cb7:	74 6f 20 
    3cba:	48 ba 72 65 61 64 20 	movabs $0x6165682064616572,%rdx
    3cc1:	68 65 61 
    3cc4:	49 89 47 10          	mov    %rax,0x10(%r15)
    3cc8:	49 89 57 18          	mov    %rdx,0x18(%r15)
    3ccc:	48 b8 64 65 72 73 20 	movabs $0x6f72662073726564,%rax
    3cd3:	66 72 6f 
    3cd6:	48 ba 6d 20 73 65 72 	movabs $0x726576726573206d,%rdx
    3cdd:	76 65 72 
    3ce0:	49 89 47 20          	mov    %rax,0x20(%r15)
    3ce4:	49 89 57 28          	mov    %rdx,0x28(%r15)
    3ce8:	41 c6 47 30 00       	movb   $0x0,0x30(%r15)
    3ced:	44 89 e7             	mov    %r12d,%edi
    3cf0:	e8 ab e5 ff ff       	call   22a0 <close@plt>
    3cf5:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    3cfa:	e9 f1 fc ff ff       	jmp    39f0 <submitr+0x4f0>
    3cff:	e8 7c e5 ff ff       	call   2280 <__stack_chk_fail@plt>

0000000000003d04 <init_timeout>:
    3d04:	f3 0f 1e fa          	endbr64 
    3d08:	85 ff                	test   %edi,%edi
    3d0a:	75 01                	jne    3d0d <init_timeout+0x9>
    3d0c:	c3                   	ret    
    3d0d:	53                   	push   %rbx
    3d0e:	89 fb                	mov    %edi,%ebx
    3d10:	48 8d 35 e7 f6 ff ff 	lea    -0x919(%rip),%rsi        # 33fe <sigalrm_handler>
    3d17:	bf 0e 00 00 00       	mov    $0xe,%edi
    3d1c:	e8 bf e5 ff ff       	call   22e0 <signal@plt>
    3d21:	85 db                	test   %ebx,%ebx
    3d23:	b8 00 00 00 00       	mov    $0x0,%eax
    3d28:	0f 49 c3             	cmovns %ebx,%eax
    3d2b:	89 c7                	mov    %eax,%edi
    3d2d:	e8 5e e5 ff ff       	call   2290 <alarm@plt>
    3d32:	5b                   	pop    %rbx
    3d33:	c3                   	ret    

0000000000003d34 <init_driver>:
    3d34:	f3 0f 1e fa          	endbr64 
    3d38:	41 54                	push   %r12
    3d3a:	55                   	push   %rbp
    3d3b:	53                   	push   %rbx
    3d3c:	48 83 ec 20          	sub    $0x20,%rsp
    3d40:	48 89 fd             	mov    %rdi,%rbp
    3d43:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    3d4a:	00 00 
    3d4c:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    3d51:	31 c0                	xor    %eax,%eax
    3d53:	be 01 00 00 00       	mov    $0x1,%esi
    3d58:	bf 0d 00 00 00       	mov    $0xd,%edi
    3d5d:	e8 7e e5 ff ff       	call   22e0 <signal@plt>
    3d62:	be 01 00 00 00       	mov    $0x1,%esi
    3d67:	bf 1d 00 00 00       	mov    $0x1d,%edi
    3d6c:	e8 6f e5 ff ff       	call   22e0 <signal@plt>
    3d71:	be 01 00 00 00       	mov    $0x1,%esi
    3d76:	bf 1d 00 00 00       	mov    $0x1d,%edi
    3d7b:	e8 60 e5 ff ff       	call   22e0 <signal@plt>
    3d80:	ba 00 00 00 00       	mov    $0x0,%edx
    3d85:	be 01 00 00 00       	mov    $0x1,%esi
    3d8a:	bf 02 00 00 00       	mov    $0x2,%edi
    3d8f:	e8 3c e6 ff ff       	call   23d0 <socket@plt>
    3d94:	85 c0                	test   %eax,%eax
    3d96:	0f 88 9c 00 00 00    	js     3e38 <init_driver+0x104>
    3d9c:	89 c3                	mov    %eax,%ebx
    3d9e:	48 8d 3d e7 13 00 00 	lea    0x13e7(%rip),%rdi        # 518c <array.0+0xfec>
    3da5:	e8 46 e5 ff ff       	call   22f0 <gethostbyname@plt>
    3daa:	48 85 c0             	test   %rax,%rax
    3dad:	0f 84 d1 00 00 00    	je     3e84 <init_driver+0x150>
    3db3:	49 89 e4             	mov    %rsp,%r12
    3db6:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
    3dbd:	00 
    3dbe:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
    3dc5:	00 00 
    3dc7:	66 c7 04 24 02 00    	movw   $0x2,(%rsp)
    3dcd:	48 63 50 14          	movslq 0x14(%rax),%rdx
    3dd1:	48 8b 40 18          	mov    0x18(%rax),%rax
    3dd5:	48 8d 7c 24 04       	lea    0x4(%rsp),%rdi
    3dda:	b9 0c 00 00 00       	mov    $0xc,%ecx
    3ddf:	48 8b 30             	mov    (%rax),%rsi
    3de2:	e8 19 e5 ff ff       	call   2300 <__memmove_chk@plt>
    3de7:	66 c7 44 24 02 3b 6e 	movw   $0x6e3b,0x2(%rsp)
    3dee:	ba 10 00 00 00       	mov    $0x10,%edx
    3df3:	4c 89 e6             	mov    %r12,%rsi
    3df6:	89 df                	mov    %ebx,%edi
    3df8:	e8 83 e5 ff ff       	call   2380 <connect@plt>
    3dfd:	85 c0                	test   %eax,%eax
    3dff:	0f 88 e7 00 00 00    	js     3eec <init_driver+0x1b8>
    3e05:	89 df                	mov    %ebx,%edi
    3e07:	e8 94 e4 ff ff       	call   22a0 <close@plt>
    3e0c:	66 c7 45 00 4f 4b    	movw   $0x4b4f,0x0(%rbp)
    3e12:	c6 45 02 00          	movb   $0x0,0x2(%rbp)
    3e16:	b8 00 00 00 00       	mov    $0x0,%eax
    3e1b:	48 8b 54 24 18       	mov    0x18(%rsp),%rdx
    3e20:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    3e27:	00 00 
    3e29:	0f 85 f5 00 00 00    	jne    3f24 <init_driver+0x1f0>
    3e2f:	48 83 c4 20          	add    $0x20,%rsp
    3e33:	5b                   	pop    %rbx
    3e34:	5d                   	pop    %rbp
    3e35:	41 5c                	pop    %r12
    3e37:	c3                   	ret    
    3e38:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    3e3f:	3a 20 43 
    3e42:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    3e49:	20 75 6e 
    3e4c:	48 89 45 00          	mov    %rax,0x0(%rbp)
    3e50:	48 89 55 08          	mov    %rdx,0x8(%rbp)
    3e54:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    3e5b:	74 6f 20 
    3e5e:	48 ba 63 72 65 61 74 	movabs $0x7320657461657263,%rdx
    3e65:	65 20 73 
    3e68:	48 89 45 10          	mov    %rax,0x10(%rbp)
    3e6c:	48 89 55 18          	mov    %rdx,0x18(%rbp)
    3e70:	c7 45 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%rbp)
    3e77:	66 c7 45 24 74 00    	movw   $0x74,0x24(%rbp)
    3e7d:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    3e82:	eb 97                	jmp    3e1b <init_driver+0xe7>
    3e84:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
    3e8b:	3a 20 44 
    3e8e:	48 ba 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rdx
    3e95:	20 75 6e 
    3e98:	48 89 45 00          	mov    %rax,0x0(%rbp)
    3e9c:	48 89 55 08          	mov    %rdx,0x8(%rbp)
    3ea0:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    3ea7:	74 6f 20 
    3eaa:	48 ba 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rdx
    3eb1:	76 65 20 
    3eb4:	48 89 45 10          	mov    %rax,0x10(%rbp)
    3eb8:	48 89 55 18          	mov    %rdx,0x18(%rbp)
    3ebc:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
    3ec3:	72 20 61 
    3ec6:	48 89 45 20          	mov    %rax,0x20(%rbp)
    3eca:	c7 45 28 64 64 72 65 	movl   $0x65726464,0x28(%rbp)
    3ed1:	66 c7 45 2c 73 73    	movw   $0x7373,0x2c(%rbp)
    3ed7:	c6 45 2e 00          	movb   $0x0,0x2e(%rbp)
    3edb:	89 df                	mov    %ebx,%edi
    3edd:	e8 be e3 ff ff       	call   22a0 <close@plt>
    3ee2:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    3ee7:	e9 2f ff ff ff       	jmp    3e1b <init_driver+0xe7>
    3eec:	4c 8d 05 99 12 00 00 	lea    0x1299(%rip),%r8        # 518c <array.0+0xfec>
    3ef3:	48 8d 0d 4e 12 00 00 	lea    0x124e(%rip),%rcx        # 5148 <array.0+0xfa8>
    3efa:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    3f01:	be 01 00 00 00       	mov    $0x1,%esi
    3f06:	48 89 ef             	mov    %rbp,%rdi
    3f09:	b8 00 00 00 00       	mov    $0x0,%eax
    3f0e:	e8 ad e4 ff ff       	call   23c0 <__sprintf_chk@plt>
    3f13:	89 df                	mov    %ebx,%edi
    3f15:	e8 86 e3 ff ff       	call   22a0 <close@plt>
    3f1a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    3f1f:	e9 f7 fe ff ff       	jmp    3e1b <init_driver+0xe7>
    3f24:	e8 57 e3 ff ff       	call   2280 <__stack_chk_fail@plt>

0000000000003f29 <driver_post>:
    3f29:	f3 0f 1e fa          	endbr64 
    3f2d:	53                   	push   %rbx
    3f2e:	4c 89 c3             	mov    %r8,%rbx
    3f31:	85 c9                	test   %ecx,%ecx
    3f33:	75 17                	jne    3f4c <driver_post+0x23>
    3f35:	48 85 ff             	test   %rdi,%rdi
    3f38:	74 05                	je     3f3f <driver_post+0x16>
    3f3a:	80 3f 00             	cmpb   $0x0,(%rdi)
    3f3d:	75 33                	jne    3f72 <driver_post+0x49>
    3f3f:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
    3f44:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
    3f48:	89 c8                	mov    %ecx,%eax
    3f4a:	5b                   	pop    %rbx
    3f4b:	c3                   	ret    
    3f4c:	48 8d 35 52 12 00 00 	lea    0x1252(%rip),%rsi        # 51a5 <array.0+0x1005>
    3f53:	bf 01 00 00 00       	mov    $0x1,%edi
    3f58:	b8 00 00 00 00       	mov    $0x0,%eax
    3f5d:	e8 de e3 ff ff       	call   2340 <__printf_chk@plt>
    3f62:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
    3f67:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
    3f6b:	b8 00 00 00 00       	mov    $0x0,%eax
    3f70:	eb d8                	jmp    3f4a <driver_post+0x21>
    3f72:	41 50                	push   %r8
    3f74:	52                   	push   %rdx
    3f75:	4c 8d 0d 40 12 00 00 	lea    0x1240(%rip),%r9        # 51bc <array.0+0x101c>
    3f7c:	49 89 f0             	mov    %rsi,%r8
    3f7f:	48 89 f9             	mov    %rdi,%rcx
    3f82:	48 8d 15 37 12 00 00 	lea    0x1237(%rip),%rdx        # 51c0 <array.0+0x1020>
    3f89:	be 6e 3b 00 00       	mov    $0x3b6e,%esi
    3f8e:	48 8d 3d f7 11 00 00 	lea    0x11f7(%rip),%rdi        # 518c <array.0+0xfec>
    3f95:	e8 66 f5 ff ff       	call   3500 <submitr>
    3f9a:	48 83 c4 10          	add    $0x10,%rsp
    3f9e:	eb aa                	jmp    3f4a <driver_post+0x21>

Disassembly of section .fini:

0000000000003fa0 <_fini>:
    3fa0:	f3 0f 1e fa          	endbr64 
    3fa4:	48 83 ec 08          	sub    $0x8,%rsp
    3fa8:	48 83 c4 08          	add    $0x8,%rsp
    3fac:	c3                   	ret    
