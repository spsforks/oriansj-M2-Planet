/* Copyright (C) 2024 Gtker
 * This file is part of M2-Planet.
 *
 * M2-Planet is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * M2-Planet is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with M2-Planet.  If not, see <http://www.gnu.org/licenses/>.
 */

int loop_variables() {
	int a = 0;
	int i = 0;
	do {
		int j = a + a;

		/* Ensure that loop variables are initialized correctly. */
		if(j > 2) return 1;

		j += 1;
		i += 1;
	} while(i < 5);

	i = 0;
	while(i < 5) {
		int j = a + a;

		/* Ensure that loop variables are initialized correctly. */
		if(j > 2) return 1;

		j += 1;
		i += 1;
	}

	for(i = 0; i < 5; i += 1) {
		int j = a + a;

		/* Ensure that loop variables are initialized correctly. */
		if(j > 2) return 1;

		j += 1;
		i += 1;
	}

	return 0;
}

struct T {
	int a;
	int b;
};

struct T global_struct_initialized = {16, 32};

struct {
	int a;
	int b;
	char c;
	char d;
} global_struct_partially_initialized = {8, 16};

int global_uninitialized;
int global_initialized = 1 + 2 + 3 + 4;

int global_array_initialized[3] = {10, 20, 30};
int global_array_partially_initialized[5] = {10 };
int global_array_no_size[] = {40, 50, 60};
char global_char_array[] = { 1, 2, 3, 4 };

struct {
	int a;
	int b;
	char c;
	char d;
} struct_array_initialized[] = {{12, 14, 10, 11}, {1, 2, 3, 4}};

struct {
	int a;
	int b;
	int c;
	int d;
} struct_array_partially_initialized[3] = {{12, 14}, {1}};

int function_called = 0;

void some_function() {
	function_called = 1;
}

int some_global_function(void) {
	function_called = 1;
}

struct {
	int* zero;
	int* global;
	void* func;
	char* str;
} struct_pointers = {0, &function_called, &some_function, "str"};

struct PointerTypeQualifiers {
	char* const ci;
	int* const li;
	struct T* const ls;
	void* const lv;

	const char* const cci;
	const int* const cli;
	const struct T* const cls;
	const void* const clv;

	const char* restrict rci;
	const int* restrict rli;
	const struct T* restrict rls;
	const void* restrict rlv;

	const char* const restrict crci;
	const int* const restrict crli;
	const struct T* const restrict crls;
	const void* const restrict crlv;
};

void pointer_type_qualifiers(
		char* const p,
		struct T* const s,
		void * const v,

		const char* restrict rp,
		struct T* restrict rs,
		void * restrict rv,

		const char* const restrict crp,
		struct T* const restrict crs,
		void * const restrict crv)
{
	char* const ci;
	int* const li;
	struct T* const ls;
	void* const lv;

	const char* const cci;
	const int* const cli;
	const struct T* const cls;
	const void* const clv;

	const char* restrict rci;
	const int* restrict rli;
	const struct T* restrict rls;
	const void* restrict rlv;

	const char* const restrict crci;
	const int* const restrict crli;
	const struct T* const restrict crls;
	const void* const restrict crlv;
}

int ga = 0, gb = 1, gc = 2, *gptr_zero = 0, *gptr, gd, garr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, (*gfunc)(void);

int main() {
	int a = 0, b = 1, c = 2, d, arr[10];
	d = 3;

	if (a != 0) return 1;
	if (b != 1) return 2;
	if (c != 2) return 3;
	if (d != 3) return 4;

	/* ensure variables aren't overlapping */
	b = 3;
	if (a != 0) return 5;
	if (b != 3) return 6;
	if (c != 2) return 7;
	if (d != 3) return 8;

	int e = 5, *f;
	f = &e;

	if(e  != 5) return 9;
	if(*f != 5) return 10;

	*f = 10;
	if(e !=  10) return 11;
	if(*f != 10) return 12;

	struct T t, t2, *t3;
	t.a = 1;
	t.b = 2;

	t2.a = 10;
	t2.b = 11;

	t3 = &t2;

	if(t.a != 1 && t.b != 2) return 13;
	if(t2.a != 10 && t2.b != 11) return 14;
	if(t3->a != 10 && t3->b != 11) return 15;

	int* g, h = 1, *i;
	g = &h;
	i = g;

	if(h != 1) return 16;
	if(*g != 1) return 17;
	if(*i != 1) return 18;

	arr[0] = 10;
	arr[1] = 9;
	arr[2] = 8;
	arr[3] = 7;
	arr[4] = 6;
	arr[5] = 5;
	arr[6] = 4;
	arr[7] = 3;
	arr[8] = 2;
	arr[9] = 1;

	if(arr[0] != 10) return 19;
	if(arr[1] != 9) return 20;
	if(arr[2] != 8) return 21;
	if(arr[3] != 7) return 22;
	if(arr[4] != 6) return 23;
	if(arr[5] != 5) return 24;
	if(arr[6] != 4) return 25;
	if(arr[7] != 3) return 26;
	if(arr[8] != 2) return 27;
	if(arr[9] != 1) return 28;

	if(loop_variables() != 0) return 29;

	if(global_uninitialized != 0) return 30;
	if(global_initialized != 10) return 31;

	if(global_array_initialized[0] != 10) return 32;
	if(global_array_initialized[1] != 20) return 33;
	if(global_array_initialized[2] != 30) return 34;

	if(global_array_partially_initialized[0] != 10) return 35;
	if(global_array_partially_initialized[1] != 0) return 36;
	if(global_array_partially_initialized[2] != 0) return 37;
	if(global_array_partially_initialized[3] != 0) return 38;
	if(global_array_partially_initialized[4] != 0) return 39;

	if(global_array_no_size[0] != 40) return 40;
	if(global_array_no_size[1] != 50) return 41;
	if(global_array_no_size[2] != 60) return 42;

	if(sizeof(global_char_array) != 4) return 43;

	if(global_struct_initialized.a != 16) return 44;
	if(global_struct_initialized.b != 32) return 45;

	if(global_struct_partially_initialized.a != 8) return 46;
	if(global_struct_partially_initialized.b != 16) return 47;
	if(global_struct_partially_initialized.c != 0) return 48;
	if(global_struct_partially_initialized.d != 0) return 49;

	if(struct_array_initialized[0].a != 12) return 50;
	if(struct_array_initialized[0].b != 14) return 51;
	if(struct_array_initialized[0].c != 10) return 52;
	if(struct_array_initialized[0].d != 11) return 53;
	if(struct_array_initialized[1].a != 1) return 54;
	if(struct_array_initialized[1].b != 2) return 55;
	if(struct_array_initialized[1].c != 3) return 56;
	if(struct_array_initialized[1].d != 4) return 57;

	if(struct_array_partially_initialized[0].a != 12) return 58;
	if(struct_array_partially_initialized[0].b != 14) return 59;
	if(struct_array_partially_initialized[0].c != 0) return 60;
	if(struct_array_partially_initialized[0].d != 0) return 61;
	if(struct_array_partially_initialized[1].a != 1) return 62;
	if(struct_array_partially_initialized[1].b != 0) return 63;
	if(struct_array_partially_initialized[1].c != 0) return 64;
	if(struct_array_partially_initialized[1].d != 0) return 65;
	if(struct_array_partially_initialized[2].a != 0) return 62;
	if(struct_array_partially_initialized[2].b != 0) return 63;
	if(struct_array_partially_initialized[2].c != 0) return 64;
	if(struct_array_partially_initialized[2].d != 0) return 65;

	if(struct_pointers.zero != 0) return 66;
	if(function_called != 0) return 67;
	int* glob = struct_pointers.global;

	if(*glob != 0) return 68;
	FUNCTION f = struct_pointers.func;
	f();
	if(function_called != 1) return 69;
	if(*glob != 1) return 70;

	char* s = struct_pointers.str;
	if(s[0] != 's') return 71;
	if(s[1] != 't') return 72;
	if(s[2] != 'r') return 73;
	if(s[3] != '\0') return 74;

	if(ga != 0) return 75;
	if(gb != 1) return 76;
	if(gc != 2) return 77;
	if(gd != 0) return 78;

	if(garr[0] != 10) return 79;
	if(garr[1] != 9) return 80;
	if(garr[2] != 8) return 81;
	if(garr[3] != 7) return 82;
	if(garr[4] != 6) return 83;
	if(garr[5] != 5) return 84;
	if(garr[6] != 4) return 85;
	if(garr[7] != 3) return 86;
	if(garr[8] != 2) return 87;
	if(garr[9] != 1) return 88;

	gfunc = some_global_function;

	if(gptr_zero != 0) return 89;
	if(sizeof(gptr) != sizeof(int*)) return 90;

	return 0;
}
