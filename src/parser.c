#include "tree_sitter/parser.h"

#define STATE_COUNT 521
#define SYMBOL_COUNT 101

enum {
    sym_source_file = ts_builtin_sym_start,
    sym_package_clause,
    sym_import_declaration,
    sym_import_spec,
    sym__top_level_declaration,
    sym__declaration,
    sym_const_declaration,
    sym_const_spec,
    sym_var_declaration,
    sym_var_spec,
    sym_function_declaration,
    sym_method_declaration,
    sym_parameters,
    sym__parameter_list,
    sym_parameter_declaration,
    sym_type_declaration,
    sym_type_spec,
    sym_identifier_list,
    sym_expression_list,
    sym__type,
    sym_pointer_type,
    sym_array_type,
    sym_slice_type,
    sym_struct_type,
    sym_field_declaration,
    sym_interface_type,
    sym_method_spec,
    sym_map_type,
    sym_channel_type,
    sym_function_type,
    sym_block,
    sym__statement,
    sym__expression,
    sym_call_expression,
    sym_unary_expression,
    sym_binary_expression,
    sym__primary_expression,
    sym_qualified_identifier,
    sym__string_literal,
    sym_int_literal,
    sym_float_literal,
    aux_sym_source_file_repeat1,
    aux_sym_source_file_repeat2,
    aux_sym_import_declaration_repeat1,
    aux_sym_const_declaration_repeat1,
    aux_sym_var_declaration_repeat1,
    aux_sym_type_declaration_repeat1,
    aux_sym_identifier_list_repeat1,
    aux_sym_expression_list_repeat1,
    aux_sym_struct_type_repeat1,
    aux_sym_interface_type_repeat1,
    aux_sym_block_repeat1,
    aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH,
    anon_sym_package,
    anon_sym_import,
    anon_sym_LPAREN,
    anon_sym_RPAREN,
    anon_sym_DOT,
    anon_sym_const,
    anon_sym_EQ,
    anon_sym_var,
    anon_sym_func,
    anon_sym_COMMA,
    anon_sym_type,
    anon_sym_STAR,
    anon_sym_LBRACK,
    anon_sym_RBRACK,
    anon_sym_struct,
    anon_sym_LBRACE,
    anon_sym_RBRACE,
    anon_sym_interface,
    anon_sym_map,
    anon_sym_chan,
    anon_sym_LT_DASH,
    anon_sym_SLASH,
    anon_sym_PERCENT,
    anon_sym_LT_LT,
    anon_sym_GT_GT,
    anon_sym_AMP,
    anon_sym_AMP_CARET,
    anon_sym_PLUS,
    anon_sym_DASH,
    anon_sym_PIPE,
    anon_sym_CARET,
    anon_sym_EQ_EQ,
    anon_sym_BANG_EQ,
    anon_sym_LT,
    anon_sym_LT_EQ,
    anon_sym_GT,
    anon_sym_GT_EQ,
    anon_sym_AMP_AMP,
    anon_sym_PIPE_PIPE,
    sym_identifier,
    sym_raw_string_literal,
    sym_interpreted_string_literal,
    aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH,
    aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH,
    aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH,
    sym_comment,
};

static const char *ts_symbol_names[] = {
    [sym_source_file] = "source_file",
    [sym_package_clause] = "package_clause",
    [sym_import_declaration] = "import_declaration",
    [sym_import_spec] = "import_spec",
    [sym__top_level_declaration] = "_top_level_declaration",
    [sym__declaration] = "_declaration",
    [sym_const_declaration] = "const_declaration",
    [sym_const_spec] = "const_spec",
    [sym_var_declaration] = "var_declaration",
    [sym_var_spec] = "var_spec",
    [sym_function_declaration] = "function_declaration",
    [sym_method_declaration] = "method_declaration",
    [sym_parameters] = "parameters",
    [sym__parameter_list] = "_parameter_list",
    [sym_parameter_declaration] = "parameter_declaration",
    [sym_type_declaration] = "type_declaration",
    [sym_type_spec] = "type_spec",
    [sym_identifier_list] = "identifier_list",
    [sym_expression_list] = "expression_list",
    [sym__type] = "_type",
    [sym_pointer_type] = "pointer_type",
    [sym_array_type] = "array_type",
    [sym_slice_type] = "slice_type",
    [sym_struct_type] = "struct_type",
    [sym_field_declaration] = "field_declaration",
    [sym_interface_type] = "interface_type",
    [sym_method_spec] = "method_spec",
    [sym_map_type] = "map_type",
    [sym_channel_type] = "channel_type",
    [sym_function_type] = "function_type",
    [sym_block] = "block",
    [sym__statement] = "_statement",
    [sym__expression] = "_expression",
    [sym_call_expression] = "call_expression",
    [sym_unary_expression] = "unary_expression",
    [sym_binary_expression] = "binary_expression",
    [sym__primary_expression] = "_primary_expression",
    [sym_qualified_identifier] = "qualified_identifier",
    [sym__string_literal] = "_string_literal",
    [sym_int_literal] = "int_literal",
    [sym_float_literal] = "float_literal",
    [aux_sym_source_file_repeat1] = "source_file_repeat1",
    [aux_sym_source_file_repeat2] = "source_file_repeat2",
    [aux_sym_import_declaration_repeat1] = "import_declaration_repeat1",
    [aux_sym_const_declaration_repeat1] = "const_declaration_repeat1",
    [aux_sym_var_declaration_repeat1] = "var_declaration_repeat1",
    [aux_sym_type_declaration_repeat1] = "type_declaration_repeat1",
    [aux_sym_identifier_list_repeat1] = "identifier_list_repeat1",
    [aux_sym_expression_list_repeat1] = "expression_list_repeat1",
    [aux_sym_struct_type_repeat1] = "struct_type_repeat1",
    [aux_sym_interface_type_repeat1] = "interface_type_repeat1",
    [aux_sym_block_repeat1] = "block_repeat1",
    [ts_builtin_sym_error] = "ERROR",
    [ts_builtin_sym_end] = "END",
    [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = "/(\n|;)/",
    [anon_sym_package] = "package",
    [anon_sym_import] = "import",
    [anon_sym_LPAREN] = "(",
    [anon_sym_RPAREN] = ")",
    [anon_sym_DOT] = ".",
    [anon_sym_const] = "const",
    [anon_sym_EQ] = "=",
    [anon_sym_var] = "var",
    [anon_sym_func] = "func",
    [anon_sym_COMMA] = ",",
    [anon_sym_type] = "type",
    [anon_sym_STAR] = "*",
    [anon_sym_LBRACK] = "[",
    [anon_sym_RBRACK] = "]",
    [anon_sym_struct] = "struct",
    [anon_sym_LBRACE] = "{",
    [anon_sym_RBRACE] = "}",
    [anon_sym_interface] = "interface",
    [anon_sym_map] = "map",
    [anon_sym_chan] = "chan",
    [anon_sym_LT_DASH] = "<-",
    [anon_sym_SLASH] = "/",
    [anon_sym_PERCENT] = "%",
    [anon_sym_LT_LT] = "<<",
    [anon_sym_GT_GT] = ">>",
    [anon_sym_AMP] = "&",
    [anon_sym_AMP_CARET] = "&^",
    [anon_sym_PLUS] = "+",
    [anon_sym_DASH] = "-",
    [anon_sym_PIPE] = "|",
    [anon_sym_CARET] = "^",
    [anon_sym_EQ_EQ] = "==",
    [anon_sym_BANG_EQ] = "!=",
    [anon_sym_LT] = "<",
    [anon_sym_LT_EQ] = "<=",
    [anon_sym_GT] = ">",
    [anon_sym_GT_EQ] = ">=",
    [anon_sym_AMP_AMP] = "&&",
    [anon_sym_PIPE_PIPE] = "||",
    [sym_identifier] = "identifier",
    [sym_raw_string_literal] = "raw_string_literal",
    [sym_interpreted_string_literal] = "interpreted_string_literal",
    [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = "/[1-9]([0-9]*|)/",
    [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = "/0([0-7]*|)/",
    [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = "/0(x|X)[0-7]*/",
    [sym_comment] = "comment",
};

static const TSSymbolMetadata ts_symbol_metadata[SYMBOL_COUNT] = {
    [sym_source_file] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_package_clause] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_import_declaration] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_import_spec] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym__top_level_declaration] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym__declaration] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym_const_declaration] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_const_spec] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_var_declaration] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_var_spec] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_function_declaration] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_method_declaration] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_parameters] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym__parameter_list] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym_parameter_declaration] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_type_declaration] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_type_spec] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_identifier_list] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_expression_list] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym__type] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym_pointer_type] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_array_type] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_slice_type] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_struct_type] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_field_declaration] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_interface_type] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_method_spec] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_map_type] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_channel_type] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_function_type] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_block] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym__statement] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym__expression] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym_call_expression] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_unary_expression] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_binary_expression] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym__primary_expression] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym_qualified_identifier] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym__string_literal] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym_int_literal] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_float_literal] = {.visible = true, .named = true, .structural = true, .extra = false},
    [aux_sym_source_file_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_source_file_repeat2] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_import_declaration_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_const_declaration_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_var_declaration_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_type_declaration_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_identifier_list_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_expression_list_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_struct_type_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_interface_type_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_block_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [ts_builtin_sym_error] = {.visible = true, .named = true, .structural = true, .extra = false},
    [ts_builtin_sym_end] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = {.visible = false, .named = false, .structural = true, .extra = false},
    [anon_sym_package] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_import] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LPAREN] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_RPAREN] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_DOT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_const] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_var] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_func] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_COMMA] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_type] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_STAR] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LBRACK] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_RBRACK] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_struct] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LBRACE] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_RBRACE] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_interface] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_map] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_chan] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LT_DASH] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_SLASH] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_PERCENT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LT_LT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_GT_GT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_AMP] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_AMP_CARET] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_PLUS] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_DASH] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_PIPE] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_CARET] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_EQ_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_BANG_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LT_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_GT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_GT_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_AMP_AMP] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_PIPE_PIPE] = {.visible = true, .named = false, .structural = true, .extra = false},
    [sym_identifier] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_raw_string_literal] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_interpreted_string_literal] = {.visible = true, .named = true, .structural = true, .extra = false},
    [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym_comment] = {.visible = true, .named = true, .structural = false, .extra = true},
};

static TSTree *ts_lex(TSLexer *lexer, TSStateId state, bool error_mode) {
    START_LEXER();
    switch (state) {
        case 0:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(1);
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(0);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '!')
                ADVANCE(3);
            if (lookahead == '\"')
                ADVANCE(5);
            if (lookahead == '%')
                ADVANCE(7);
            if (lookahead == '&')
                ADVANCE(8);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == ')')
                ADVANCE(12);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '+')
                ADVANCE(14);
            if (lookahead == ',')
                ADVANCE(15);
            if (lookahead == '-')
                ADVANCE(16);
            if (lookahead == '.')
                ADVANCE(17);
            if (lookahead == '/')
                ADVANCE(18);
            if (lookahead == '0')
                ADVANCE(20);
            if ('1' <= lookahead && lookahead <= '9')
                ADVANCE(24);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '<')
                ADVANCE(26);
            if (lookahead == '=')
                ADVANCE(30);
            if (lookahead == '>')
                ADVANCE(32);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                (lookahead == 'n') ||
                (lookahead == 'o') ||
                (lookahead == 'q') ||
                (lookahead == 'r') ||
                (lookahead == 'u') ||
                ('w' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == ']')
                ADVANCE(37);
            if (lookahead == '^')
                ADVANCE(38);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == '`')
                ADVANCE(39);
            if (lookahead == 'c')
                ADVANCE(41);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(53);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 'p')
                ADVANCE(70);
            if (lookahead == 's')
                ADVANCE(77);
            if (lookahead == 't')
                ADVANCE(83);
            if (lookahead == 'v')
                ADVANCE(87);
            if (lookahead == '{')
                ADVANCE(90);
            if (lookahead == '|')
                ADVANCE(91);
            if (lookahead == '}')
                ADVANCE(93);
            LEX_ERROR();
        case 1:
            ACCEPT_TOKEN(ts_builtin_sym_end);
        case 2:
            START_TOKEN();
            ACCEPT_TOKEN(aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH);
        case 3:
            if (lookahead == '=')
                ADVANCE(4);
            LEX_ERROR();
        case 4:
            ACCEPT_TOKEN(anon_sym_BANG_EQ);
        case 5:
            if (lookahead == '\"')
                ADVANCE(6);
            if (!((lookahead == 0) ||
                (lookahead == '\n') ||
                (lookahead == '\"')))
                ADVANCE(5);
            LEX_ERROR();
        case 6:
            ACCEPT_TOKEN(sym_interpreted_string_literal);
        case 7:
            ACCEPT_TOKEN(anon_sym_PERCENT);
        case 8:
            if (lookahead == '&')
                ADVANCE(9);
            if (lookahead == '^')
                ADVANCE(10);
            ACCEPT_TOKEN(anon_sym_AMP);
        case 9:
            ACCEPT_TOKEN(anon_sym_AMP_AMP);
        case 10:
            ACCEPT_TOKEN(anon_sym_AMP_CARET);
        case 11:
            ACCEPT_TOKEN(anon_sym_LPAREN);
        case 12:
            ACCEPT_TOKEN(anon_sym_RPAREN);
        case 13:
            ACCEPT_TOKEN(anon_sym_STAR);
        case 14:
            ACCEPT_TOKEN(anon_sym_PLUS);
        case 15:
            ACCEPT_TOKEN(anon_sym_COMMA);
        case 16:
            ACCEPT_TOKEN(anon_sym_DASH);
        case 17:
            ACCEPT_TOKEN(anon_sym_DOT);
        case 18:
            if (lookahead == '/')
                ADVANCE(19);
            ACCEPT_TOKEN(anon_sym_SLASH);
        case 19:
            if (!((lookahead == 0) ||
                (lookahead == '\n')))
                ADVANCE(19);
            ACCEPT_TOKEN(sym_comment);
        case 20:
            if ('0' <= lookahead && lookahead <= '7')
                ADVANCE(21);
            if (lookahead == 'X')
                ADVANCE(22);
            if (lookahead == 'x')
                ADVANCE(22);
            ACCEPT_TOKEN(aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH);
        case 21:
            if ('0' <= lookahead && lookahead <= '7')
                ADVANCE(21);
            ACCEPT_TOKEN(aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH);
        case 22:
            if ('0' <= lookahead && lookahead <= '7')
                ADVANCE(23);
            LEX_ERROR();
        case 23:
            if ('0' <= lookahead && lookahead <= '7')
                ADVANCE(23);
            ACCEPT_TOKEN(aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH);
        case 24:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(24);
            ACCEPT_TOKEN(aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH);
        case 25:
            ACCEPT_TOKEN(aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH);
        case 26:
            if (lookahead == '-')
                ADVANCE(27);
            if (lookahead == '<')
                ADVANCE(28);
            if (lookahead == '=')
                ADVANCE(29);
            ACCEPT_TOKEN(anon_sym_LT);
        case 27:
            ACCEPT_TOKEN(anon_sym_LT_DASH);
        case 28:
            ACCEPT_TOKEN(anon_sym_LT_LT);
        case 29:
            ACCEPT_TOKEN(anon_sym_LT_EQ);
        case 30:
            if (lookahead == '=')
                ADVANCE(31);
            ACCEPT_TOKEN(anon_sym_EQ);
        case 31:
            ACCEPT_TOKEN(anon_sym_EQ_EQ);
        case 32:
            if (lookahead == '=')
                ADVANCE(33);
            if (lookahead == '>')
                ADVANCE(34);
            ACCEPT_TOKEN(anon_sym_GT);
        case 33:
            ACCEPT_TOKEN(anon_sym_GT_EQ);
        case 34:
            ACCEPT_TOKEN(anon_sym_GT_GT);
        case 35:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 36:
            ACCEPT_TOKEN(anon_sym_LBRACK);
        case 37:
            ACCEPT_TOKEN(anon_sym_RBRACK);
        case 38:
            ACCEPT_TOKEN(anon_sym_CARET);
        case 39:
            if (lookahead == '`')
                ADVANCE(40);
            if (!((lookahead == 0) ||
                (lookahead == '\n') ||
                (lookahead == '`')))
                ADVANCE(39);
            LEX_ERROR();
        case 40:
            ACCEPT_TOKEN(sym_raw_string_literal);
        case 41:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'g') ||
                ('i' <= lookahead && lookahead <= 'n') ||
                ('p' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'h')
                ADVANCE(42);
            if (lookahead == 'o')
                ADVANCE(45);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 42:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'a')
                ADVANCE(43);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 43:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'n')
                ADVANCE(44);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 44:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            ACCEPT_TOKEN(anon_sym_chan);
        case 45:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'n')
                ADVANCE(46);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 46:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 's')
                ADVANCE(47);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 47:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 't')
                ADVANCE(48);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 48:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            ACCEPT_TOKEN(anon_sym_const);
        case 49:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 't') ||
                ('v' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'u')
                ADVANCE(50);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 50:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'n')
                ADVANCE(51);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 51:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                ('d' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(52);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 52:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            ACCEPT_TOKEN(anon_sym_func);
        case 53:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'm')
                ADVANCE(54);
            if (lookahead == 'n')
                ADVANCE(59);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 54:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'o') ||
                ('q' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'p')
                ADVANCE(55);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 55:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'n') ||
                ('p' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'o')
                ADVANCE(56);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 56:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'q') ||
                ('s' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'r')
                ADVANCE(57);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 57:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 't')
                ADVANCE(58);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 58:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            ACCEPT_TOKEN(anon_sym_import);
        case 59:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 't')
                ADVANCE(60);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 60:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'e')
                ADVANCE(61);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 61:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'q') ||
                ('s' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'r')
                ADVANCE(62);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 62:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'e') ||
                ('g' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'f')
                ADVANCE(63);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 63:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'a')
                ADVANCE(64);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 64:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                ('d' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(65);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 65:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'e')
                ADVANCE(66);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 66:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            ACCEPT_TOKEN(anon_sym_interface);
        case 67:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'a')
                ADVANCE(68);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 68:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'o') ||
                ('q' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'p')
                ADVANCE(69);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 69:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            ACCEPT_TOKEN(anon_sym_map);
        case 70:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'a')
                ADVANCE(71);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 71:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                ('d' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(72);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 72:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'j') ||
                ('l' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'k')
                ADVANCE(73);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 73:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'a')
                ADVANCE(74);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 74:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'f') ||
                ('h' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'g')
                ADVANCE(75);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 75:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'e')
                ADVANCE(76);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 76:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            ACCEPT_TOKEN(anon_sym_package);
        case 77:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 't')
                ADVANCE(78);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 78:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'q') ||
                ('s' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'r')
                ADVANCE(79);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 79:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 't') ||
                ('v' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'u')
                ADVANCE(80);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 80:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                ('d' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(81);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 81:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 't')
                ADVANCE(82);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 82:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            ACCEPT_TOKEN(anon_sym_struct);
        case 83:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'x') ||
                (lookahead == 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'y')
                ADVANCE(84);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 84:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'o') ||
                ('q' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'p')
                ADVANCE(85);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 85:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'e')
                ADVANCE(86);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 86:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            ACCEPT_TOKEN(anon_sym_type);
        case 87:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'a')
                ADVANCE(88);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 88:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'q') ||
                ('s' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'r')
                ADVANCE(89);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 89:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            ACCEPT_TOKEN(anon_sym_var);
        case 90:
            ACCEPT_TOKEN(anon_sym_LBRACE);
        case 91:
            if (lookahead == '|')
                ADVANCE(92);
            ACCEPT_TOKEN(anon_sym_PIPE);
        case 92:
            ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
        case 93:
            ACCEPT_TOKEN(anon_sym_RBRACE);
        case 94:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(94);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == 'p')
                ADVANCE(96);
            LEX_ERROR();
        case 95:
            if (lookahead == '/')
                ADVANCE(19);
            LEX_ERROR();
        case 96:
            if (lookahead == 'a')
                ADVANCE(97);
            LEX_ERROR();
        case 97:
            if (lookahead == 'c')
                ADVANCE(98);
            LEX_ERROR();
        case 98:
            if (lookahead == 'k')
                ADVANCE(99);
            LEX_ERROR();
        case 99:
            if (lookahead == 'a')
                ADVANCE(100);
            LEX_ERROR();
        case 100:
            if (lookahead == 'g')
                ADVANCE(101);
            LEX_ERROR();
        case 101:
            if (lookahead == 'e')
                ADVANCE(102);
            LEX_ERROR();
        case 102:
            ACCEPT_TOKEN(anon_sym_package);
        case 103:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(1);
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(103);
            if (lookahead == '/')
                ADVANCE(95);
            LEX_ERROR();
        case 104:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(1);
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(104);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == 'c')
                ADVANCE(105);
            if (lookahead == 'f')
                ADVANCE(110);
            if (lookahead == 'i')
                ADVANCE(114);
            if (lookahead == 't')
                ADVANCE(120);
            if (lookahead == 'v')
                ADVANCE(124);
            LEX_ERROR();
        case 105:
            if (lookahead == 'o')
                ADVANCE(106);
            LEX_ERROR();
        case 106:
            if (lookahead == 'n')
                ADVANCE(107);
            LEX_ERROR();
        case 107:
            if (lookahead == 's')
                ADVANCE(108);
            LEX_ERROR();
        case 108:
            if (lookahead == 't')
                ADVANCE(109);
            LEX_ERROR();
        case 109:
            ACCEPT_TOKEN(anon_sym_const);
        case 110:
            if (lookahead == 'u')
                ADVANCE(111);
            LEX_ERROR();
        case 111:
            if (lookahead == 'n')
                ADVANCE(112);
            LEX_ERROR();
        case 112:
            if (lookahead == 'c')
                ADVANCE(113);
            LEX_ERROR();
        case 113:
            ACCEPT_TOKEN(anon_sym_func);
        case 114:
            if (lookahead == 'm')
                ADVANCE(115);
            LEX_ERROR();
        case 115:
            if (lookahead == 'p')
                ADVANCE(116);
            LEX_ERROR();
        case 116:
            if (lookahead == 'o')
                ADVANCE(117);
            LEX_ERROR();
        case 117:
            if (lookahead == 'r')
                ADVANCE(118);
            LEX_ERROR();
        case 118:
            if (lookahead == 't')
                ADVANCE(119);
            LEX_ERROR();
        case 119:
            ACCEPT_TOKEN(anon_sym_import);
        case 120:
            if (lookahead == 'y')
                ADVANCE(121);
            LEX_ERROR();
        case 121:
            if (lookahead == 'p')
                ADVANCE(122);
            LEX_ERROR();
        case 122:
            if (lookahead == 'e')
                ADVANCE(123);
            LEX_ERROR();
        case 123:
            ACCEPT_TOKEN(anon_sym_type);
        case 124:
            if (lookahead == 'a')
                ADVANCE(125);
            LEX_ERROR();
        case 125:
            if (lookahead == 'r')
                ADVANCE(126);
            LEX_ERROR();
        case 126:
            ACCEPT_TOKEN(anon_sym_var);
        case 127:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(127);
            if (lookahead == '/')
                ADVANCE(95);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            LEX_ERROR();
        case 128:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(128);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            LEX_ERROR();
        case 129:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(1);
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(129);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == 'c')
                ADVANCE(105);
            if (lookahead == 'f')
                ADVANCE(110);
            if (lookahead == 't')
                ADVANCE(120);
            if (lookahead == 'v')
                ADVANCE(124);
            LEX_ERROR();
        case 130:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(130);
            if (lookahead == '\"')
                ADVANCE(5);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == '.')
                ADVANCE(17);
            if (lookahead == '/')
                ADVANCE(95);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == '`')
                ADVANCE(39);
            LEX_ERROR();
        case 131:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(131);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == '/')
                ADVANCE(95);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            LEX_ERROR();
        case 132:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(132);
            if (lookahead == ')')
                ADVANCE(12);
            if (lookahead == '/')
                ADVANCE(95);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            LEX_ERROR();
        case 133:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(133);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '<')
                ADVANCE(134);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(135);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(136);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 's')
                ADVANCE(77);
            LEX_ERROR();
        case 134:
            if (lookahead == '-')
                ADVANCE(27);
            LEX_ERROR();
        case 135:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'g') ||
                ('i' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'h')
                ADVANCE(42);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 136:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'n')
                ADVANCE(59);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 137:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(137);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == '/')
                ADVANCE(95);
            LEX_ERROR();
        case 138:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(138);
            if (lookahead == '\"')
                ADVANCE(5);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '0')
                ADVANCE(20);
            if ('1' <= lookahead && lookahead <= '9')
                ADVANCE(24);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == ']')
                ADVANCE(37);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == '`')
                ADVANCE(39);
            LEX_ERROR();
        case 139:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(139);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '{')
                ADVANCE(90);
            LEX_ERROR();
        case 140:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(140);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '[')
                ADVANCE(36);
            LEX_ERROR();
        case 141:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(141);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == 'c')
                ADVANCE(142);
            LEX_ERROR();
        case 142:
            if (lookahead == 'h')
                ADVANCE(143);
            LEX_ERROR();
        case 143:
            if (lookahead == 'a')
                ADVANCE(144);
            LEX_ERROR();
        case 144:
            if (lookahead == 'n')
                ADVANCE(145);
            LEX_ERROR();
        case 145:
            ACCEPT_TOKEN(anon_sym_chan);
        case 146:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(146);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '.')
                ADVANCE(17);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            LEX_ERROR();
        case 147:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(147);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ']')
                ADVANCE(37);
            LEX_ERROR();
        case 148:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(148);
            if (lookahead == '.')
                ADVANCE(17);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ']')
                ADVANCE(37);
            LEX_ERROR();
        case 149:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(149);
            if (lookahead == '/')
                ADVANCE(95);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == '}')
                ADVANCE(93);
            LEX_ERROR();
        case 150:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(150);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '}')
                ADVANCE(93);
            LEX_ERROR();
        case 151:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(151);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            LEX_ERROR();
        case 152:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(152);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '<')
                ADVANCE(134);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(135);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(136);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 's')
                ADVANCE(77);
            LEX_ERROR();
        case 153:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(153);
            if (lookahead == ')')
                ADVANCE(12);
            if (lookahead == ',')
                ADVANCE(15);
            if (lookahead == '/')
                ADVANCE(95);
            LEX_ERROR();
        case 154:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(154);
            if (lookahead == ')')
                ADVANCE(12);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == ',')
                ADVANCE(15);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '<')
                ADVANCE(134);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(135);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(136);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 's')
                ADVANCE(77);
            LEX_ERROR();
        case 155:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(155);
            if (lookahead == ')')
                ADVANCE(12);
            if (lookahead == ',')
                ADVANCE(15);
            if (lookahead == '.')
                ADVANCE(17);
            if (lookahead == '/')
                ADVANCE(95);
            LEX_ERROR();
        case 156:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(156);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '/')
                ADVANCE(95);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == '}')
                ADVANCE(93);
            LEX_ERROR();
        case 157:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(157);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '\"')
                ADVANCE(5);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == ',')
                ADVANCE(15);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '<')
                ADVANCE(134);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == '`')
                ADVANCE(39);
            if (lookahead == 'c')
                ADVANCE(135);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(136);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 's')
                ADVANCE(77);
            LEX_ERROR();
        case 158:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(158);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == ',')
                ADVANCE(15);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '<')
                ADVANCE(134);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(135);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(136);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 's')
                ADVANCE(77);
            LEX_ERROR();
        case 159:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(159);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '\"')
                ADVANCE(5);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '`')
                ADVANCE(39);
            LEX_ERROR();
        case 160:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(160);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '\"')
                ADVANCE(5);
            if (lookahead == '.')
                ADVANCE(17);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '`')
                ADVANCE(39);
            LEX_ERROR();
        case 161:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(161);
            if (lookahead == '!')
                ADVANCE(3);
            if (lookahead == '%')
                ADVANCE(7);
            if (lookahead == '&')
                ADVANCE(8);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '+')
                ADVANCE(14);
            if (lookahead == '-')
                ADVANCE(16);
            if (lookahead == '/')
                ADVANCE(18);
            if (lookahead == '<')
                ADVANCE(162);
            if (lookahead == '=')
                ADVANCE(163);
            if (lookahead == '>')
                ADVANCE(32);
            if (lookahead == ']')
                ADVANCE(37);
            if (lookahead == '^')
                ADVANCE(38);
            if (lookahead == '|')
                ADVANCE(91);
            LEX_ERROR();
        case 162:
            if (lookahead == '<')
                ADVANCE(28);
            if (lookahead == '=')
                ADVANCE(29);
            ACCEPT_TOKEN(anon_sym_LT);
        case 163:
            if (lookahead == '=')
                ADVANCE(31);
            LEX_ERROR();
        case 164:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(164);
            if (lookahead == '\"')
                ADVANCE(5);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '0')
                ADVANCE(20);
            if ('1' <= lookahead && lookahead <= '9')
                ADVANCE(24);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == '`')
                ADVANCE(39);
            LEX_ERROR();
        case 165:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(165);
            if (lookahead == ')')
                ADVANCE(12);
            if (lookahead == '/')
                ADVANCE(95);
            LEX_ERROR();
        case 166:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(166);
            if (lookahead == '!')
                ADVANCE(3);
            if (lookahead == '%')
                ADVANCE(7);
            if (lookahead == '&')
                ADVANCE(8);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == ')')
                ADVANCE(12);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '+')
                ADVANCE(14);
            if (lookahead == ',')
                ADVANCE(15);
            if (lookahead == '-')
                ADVANCE(16);
            if (lookahead == '/')
                ADVANCE(18);
            if (lookahead == '<')
                ADVANCE(162);
            if (lookahead == '=')
                ADVANCE(163);
            if (lookahead == '>')
                ADVANCE(32);
            if (lookahead == '^')
                ADVANCE(38);
            if (lookahead == '|')
                ADVANCE(91);
            LEX_ERROR();
        case 167:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(167);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '\"')
                ADVANCE(5);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '<')
                ADVANCE(134);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == '`')
                ADVANCE(39);
            if (lookahead == 'c')
                ADVANCE(135);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(136);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 's')
                ADVANCE(77);
            LEX_ERROR();
        case 168:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(168);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == ')')
                ADVANCE(12);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == ',')
                ADVANCE(15);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '<')
                ADVANCE(134);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(135);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(136);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 's')
                ADVANCE(77);
            LEX_ERROR();
        case 169:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(169);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '<')
                ADVANCE(134);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == ']')
                ADVANCE(37);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(135);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(136);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 's')
                ADVANCE(77);
            LEX_ERROR();
        case 170:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(170);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '<')
                ADVANCE(134);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(135);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(136);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 's')
                ADVANCE(77);
            if (lookahead == '{')
                ADVANCE(90);
            LEX_ERROR();
        case 171:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(171);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '{')
                ADVANCE(90);
            LEX_ERROR();
        case 172:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(172);
            if (lookahead == '\"')
                ADVANCE(5);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '0')
                ADVANCE(20);
            if ('1' <= lookahead && lookahead <= '9')
                ADVANCE(24);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                ('d' <= lookahead && lookahead <= 's') ||
                (lookahead == 'u') ||
                ('w' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == '`')
                ADVANCE(39);
            if (lookahead == 'c')
                ADVANCE(173);
            if (lookahead == 't')
                ADVANCE(83);
            if (lookahead == 'v')
                ADVANCE(87);
            if (lookahead == '}')
                ADVANCE(93);
            LEX_ERROR();
        case 173:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(35);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'n') ||
                ('p' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'o')
                ADVANCE(45);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 174:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(174);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '.')
                ADVANCE(17);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '{')
                ADVANCE(90);
            LEX_ERROR();
        case 175:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(175);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '!')
                ADVANCE(3);
            if (lookahead == '%')
                ADVANCE(7);
            if (lookahead == '&')
                ADVANCE(8);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '+')
                ADVANCE(14);
            if (lookahead == '-')
                ADVANCE(16);
            if (lookahead == '/')
                ADVANCE(18);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '<')
                ADVANCE(162);
            if (lookahead == '=')
                ADVANCE(163);
            if (lookahead == '>')
                ADVANCE(32);
            if (lookahead == '^')
                ADVANCE(38);
            if (lookahead == '|')
                ADVANCE(91);
            LEX_ERROR();
        case 176:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(176);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '<')
                ADVANCE(134);
            if (lookahead == '=')
                ADVANCE(177);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(135);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(136);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 's')
                ADVANCE(77);
            LEX_ERROR();
        case 177:
            ACCEPT_TOKEN(anon_sym_EQ);
        case 178:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(178);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == ',')
                ADVANCE(15);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '<')
                ADVANCE(134);
            if (lookahead == '=')
                ADVANCE(177);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(135);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(136);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 's')
                ADVANCE(77);
            LEX_ERROR();
        case 179:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(179);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '=')
                ADVANCE(177);
            LEX_ERROR();
        case 180:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(180);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '.')
                ADVANCE(17);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '=')
                ADVANCE(177);
            LEX_ERROR();
        case 181:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(181);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '<')
                ADVANCE(134);
            if (lookahead == '=')
                ADVANCE(177);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(135);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(136);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 's')
                ADVANCE(77);
            LEX_ERROR();
        case 182:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(182);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '!')
                ADVANCE(3);
            if (lookahead == '%')
                ADVANCE(7);
            if (lookahead == '&')
                ADVANCE(8);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '+')
                ADVANCE(14);
            if (lookahead == ',')
                ADVANCE(15);
            if (lookahead == '-')
                ADVANCE(16);
            if (lookahead == '/')
                ADVANCE(18);
            if (lookahead == ';')
                ADVANCE(25);
            if (lookahead == '<')
                ADVANCE(162);
            if (lookahead == '=')
                ADVANCE(163);
            if (lookahead == '>')
                ADVANCE(32);
            if (lookahead == '^')
                ADVANCE(38);
            if (lookahead == '|')
                ADVANCE(91);
            LEX_ERROR();
        case 183:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(183);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '=')
                ADVANCE(177);
            LEX_ERROR();
        case 184:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(184);
            if (lookahead == '.')
                ADVANCE(17);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '=')
                ADVANCE(177);
            LEX_ERROR();
        case 185:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(185);
            if (lookahead == '(')
                ADVANCE(11);
            if (lookahead == '*')
                ADVANCE(13);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '<')
                ADVANCE(134);
            if (lookahead == '=')
                ADVANCE(177);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == 'a') ||
                (lookahead == 'b') ||
                (lookahead == 'd') ||
                (lookahead == 'e') ||
                (lookahead == 'g') ||
                (lookahead == 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('n' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '[')
                ADVANCE(36);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == 'c')
                ADVANCE(135);
            if (lookahead == 'f')
                ADVANCE(49);
            if (lookahead == 'i')
                ADVANCE(136);
            if (lookahead == 'm')
                ADVANCE(67);
            if (lookahead == 's')
                ADVANCE(77);
            LEX_ERROR();
        case 186:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(186);
            if (lookahead == '\"')
                ADVANCE(5);
            if (lookahead == ')')
                ADVANCE(12);
            if (lookahead == '.')
                ADVANCE(17);
            if (lookahead == '/')
                ADVANCE(95);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(35);
            if (lookahead == '_')
                ADVANCE(35);
            if (lookahead == '`')
                ADVANCE(39);
            LEX_ERROR();
        case 187:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(187);
            if (lookahead == '\"')
                ADVANCE(5);
            if (lookahead == '/')
                ADVANCE(95);
            if (lookahead == '`')
                ADVANCE(39);
            LEX_ERROR();
        default:
            LEX_ERROR();
    }
}

static TSStateId ts_lex_states[STATE_COUNT] = {
    [0] = 94,
    [1] = 103,
    [2] = 104,
    [3] = 127,
    [4] = 104,
    [5] = 104,
    [6] = 128,
    [7] = 128,
    [8] = 128,
    [9] = 129,
    [10] = 103,
    [11] = 130,
    [12] = 131,
    [13] = 131,
    [14] = 131,
    [15] = 131,
    [16] = 128,
    [17] = 132,
    [18] = 133,
    [19] = 128,
    [20] = 128,
    [21] = 137,
    [22] = 133,
    [23] = 138,
    [24] = 139,
    [25] = 139,
    [26] = 140,
    [27] = 133,
    [28] = 141,
    [29] = 146,
    [30] = 127,
    [31] = 128,
    [32] = 133,
    [33] = 128,
    [34] = 128,
    [35] = 133,
    [36] = 128,
    [37] = 133,
    [38] = 147,
    [39] = 147,
    [40] = 137,
    [41] = 133,
    [42] = 138,
    [43] = 139,
    [44] = 139,
    [45] = 140,
    [46] = 133,
    [47] = 141,
    [48] = 148,
    [49] = 127,
    [50] = 147,
    [51] = 133,
    [52] = 147,
    [53] = 147,
    [54] = 133,
    [55] = 147,
    [56] = 133,
    [57] = 147,
    [58] = 133,
    [59] = 147,
    [60] = 149,
    [61] = 128,
    [62] = 150,
    [63] = 147,
    [64] = 151,
    [65] = 152,
    [66] = 149,
    [67] = 132,
    [68] = 153,
    [69] = 153,
    [70] = 152,
    [71] = 154,
    [72] = 153,
    [73] = 153,
    [74] = 137,
    [75] = 133,
    [76] = 138,
    [77] = 139,
    [78] = 139,
    [79] = 140,
    [80] = 133,
    [81] = 141,
    [82] = 155,
    [83] = 127,
    [84] = 153,
    [85] = 133,
    [86] = 153,
    [87] = 153,
    [88] = 133,
    [89] = 153,
    [90] = 133,
    [91] = 147,
    [92] = 133,
    [93] = 153,
    [94] = 149,
    [95] = 150,
    [96] = 153,
    [97] = 153,
    [98] = 156,
    [99] = 133,
    [100] = 128,
    [101] = 150,
    [102] = 127,
    [103] = 153,
    [104] = 157,
    [105] = 128,
    [106] = 133,
    [107] = 127,
    [108] = 128,
    [109] = 158,
    [110] = 133,
    [111] = 159,
    [112] = 128,
    [113] = 153,
    [114] = 156,
    [115] = 150,
    [116] = 159,
    [117] = 137,
    [118] = 133,
    [119] = 138,
    [120] = 139,
    [121] = 139,
    [122] = 140,
    [123] = 133,
    [124] = 141,
    [125] = 160,
    [126] = 127,
    [127] = 159,
    [128] = 133,
    [129] = 159,
    [130] = 159,
    [131] = 133,
    [132] = 159,
    [133] = 133,
    [134] = 147,
    [135] = 133,
    [136] = 159,
    [137] = 149,
    [138] = 150,
    [139] = 159,
    [140] = 159,
    [141] = 156,
    [142] = 150,
    [143] = 159,
    [144] = 159,
    [145] = 161,
    [146] = 161,
    [147] = 161,
    [148] = 133,
    [149] = 161,
    [150] = 161,
    [151] = 159,
    [152] = 164,
    [153] = 164,
    [154] = 133,
    [155] = 164,
    [156] = 164,
    [157] = 164,
    [158] = 164,
    [159] = 161,
    [160] = 161,
    [161] = 161,
    [162] = 161,
    [163] = 161,
    [164] = 159,
    [165] = 165,
    [166] = 166,
    [167] = 166,
    [168] = 166,
    [169] = 166,
    [170] = 166,
    [171] = 165,
    [172] = 164,
    [173] = 164,
    [174] = 164,
    [175] = 164,
    [176] = 164,
    [177] = 164,
    [178] = 164,
    [179] = 166,
    [180] = 166,
    [181] = 166,
    [182] = 166,
    [183] = 166,
    [184] = 166,
    [185] = 165,
    [186] = 165,
    [187] = 166,
    [188] = 161,
    [189] = 159,
    [190] = 167,
    [191] = 132,
    [192] = 153,
    [193] = 167,
    [194] = 167,
    [195] = 127,
    [196] = 153,
    [197] = 154,
    [198] = 159,
    [199] = 132,
    [200] = 153,
    [201] = 159,
    [202] = 159,
    [203] = 161,
    [204] = 133,
    [205] = 153,
    [206] = 133,
    [207] = 153,
    [208] = 153,
    [209] = 168,
    [210] = 132,
    [211] = 153,
    [212] = 168,
    [213] = 168,
    [214] = 153,
    [215] = 132,
    [216] = 153,
    [217] = 153,
    [218] = 153,
    [219] = 152,
    [220] = 150,
    [221] = 128,
    [222] = 132,
    [223] = 153,
    [224] = 128,
    [225] = 128,
    [226] = 147,
    [227] = 156,
    [228] = 150,
    [229] = 147,
    [230] = 147,
    [231] = 161,
    [232] = 133,
    [233] = 147,
    [234] = 133,
    [235] = 147,
    [236] = 147,
    [237] = 169,
    [238] = 132,
    [239] = 153,
    [240] = 169,
    [241] = 169,
    [242] = 147,
    [243] = 132,
    [244] = 153,
    [245] = 147,
    [246] = 147,
    [247] = 133,
    [248] = 128,
    [249] = 149,
    [250] = 150,
    [251] = 128,
    [252] = 128,
    [253] = 156,
    [254] = 150,
    [255] = 128,
    [256] = 128,
    [257] = 161,
    [258] = 133,
    [259] = 128,
    [260] = 133,
    [261] = 128,
    [262] = 128,
    [263] = 152,
    [264] = 128,
    [265] = 128,
    [266] = 165,
    [267] = 128,
    [268] = 128,
    [269] = 132,
    [270] = 165,
    [271] = 127,
    [272] = 132,
    [273] = 137,
    [274] = 170,
    [275] = 132,
    [276] = 153,
    [277] = 170,
    [278] = 170,
    [279] = 171,
    [280] = 171,
    [281] = 128,
    [282] = 132,
    [283] = 137,
    [284] = 133,
    [285] = 138,
    [286] = 139,
    [287] = 172,
    [288] = 139,
    [289] = 140,
    [290] = 133,
    [291] = 141,
    [292] = 174,
    [293] = 127,
    [294] = 171,
    [295] = 133,
    [296] = 171,
    [297] = 171,
    [298] = 133,
    [299] = 171,
    [300] = 133,
    [301] = 147,
    [302] = 133,
    [303] = 171,
    [304] = 149,
    [305] = 150,
    [306] = 171,
    [307] = 171,
    [308] = 128,
    [309] = 128,
    [310] = 175,
    [311] = 175,
    [312] = 175,
    [313] = 150,
    [314] = 128,
    [315] = 175,
    [316] = 175,
    [317] = 128,
    [318] = 164,
    [319] = 164,
    [320] = 164,
    [321] = 164,
    [322] = 164,
    [323] = 164,
    [324] = 175,
    [325] = 175,
    [326] = 175,
    [327] = 175,
    [328] = 175,
    [329] = 165,
    [330] = 175,
    [331] = 172,
    [332] = 150,
    [333] = 156,
    [334] = 150,
    [335] = 171,
    [336] = 171,
    [337] = 161,
    [338] = 133,
    [339] = 171,
    [340] = 133,
    [341] = 171,
    [342] = 171,
    [343] = 170,
    [344] = 171,
    [345] = 153,
    [346] = 171,
    [347] = 171,
    [348] = 128,
    [349] = 153,
    [350] = 127,
    [351] = 127,
    [352] = 137,
    [353] = 170,
    [354] = 171,
    [355] = 128,
    [356] = 128,
    [357] = 128,
    [358] = 176,
    [359] = 132,
    [360] = 178,
    [361] = 176,
    [362] = 127,
    [363] = 178,
    [364] = 176,
    [365] = 128,
    [366] = 165,
    [367] = 128,
    [368] = 128,
    [369] = 132,
    [370] = 165,
    [371] = 179,
    [372] = 179,
    [373] = 164,
    [374] = 137,
    [375] = 133,
    [376] = 138,
    [377] = 139,
    [378] = 139,
    [379] = 140,
    [380] = 133,
    [381] = 141,
    [382] = 180,
    [383] = 127,
    [384] = 179,
    [385] = 133,
    [386] = 179,
    [387] = 179,
    [388] = 133,
    [389] = 179,
    [390] = 133,
    [391] = 147,
    [392] = 133,
    [393] = 179,
    [394] = 149,
    [395] = 150,
    [396] = 179,
    [397] = 179,
    [398] = 156,
    [399] = 150,
    [400] = 179,
    [401] = 179,
    [402] = 161,
    [403] = 133,
    [404] = 179,
    [405] = 133,
    [406] = 179,
    [407] = 179,
    [408] = 181,
    [409] = 132,
    [410] = 153,
    [411] = 181,
    [412] = 181,
    [413] = 179,
    [414] = 132,
    [415] = 153,
    [416] = 179,
    [417] = 179,
    [418] = 128,
    [419] = 182,
    [420] = 182,
    [421] = 182,
    [422] = 182,
    [423] = 182,
    [424] = 128,
    [425] = 164,
    [426] = 164,
    [427] = 164,
    [428] = 164,
    [429] = 164,
    [430] = 164,
    [431] = 164,
    [432] = 182,
    [433] = 182,
    [434] = 182,
    [435] = 182,
    [436] = 182,
    [437] = 182,
    [438] = 128,
    [439] = 165,
    [440] = 182,
    [441] = 164,
    [442] = 128,
    [443] = 128,
    [444] = 176,
    [445] = 132,
    [446] = 128,
    [447] = 165,
    [448] = 128,
    [449] = 128,
    [450] = 132,
    [451] = 165,
    [452] = 183,
    [453] = 183,
    [454] = 164,
    [455] = 137,
    [456] = 133,
    [457] = 138,
    [458] = 139,
    [459] = 139,
    [460] = 140,
    [461] = 133,
    [462] = 141,
    [463] = 184,
    [464] = 127,
    [465] = 183,
    [466] = 133,
    [467] = 183,
    [468] = 183,
    [469] = 133,
    [470] = 183,
    [471] = 133,
    [472] = 147,
    [473] = 133,
    [474] = 183,
    [475] = 149,
    [476] = 150,
    [477] = 183,
    [478] = 183,
    [479] = 156,
    [480] = 150,
    [481] = 183,
    [482] = 183,
    [483] = 161,
    [484] = 133,
    [485] = 183,
    [486] = 133,
    [487] = 183,
    [488] = 183,
    [489] = 185,
    [490] = 132,
    [491] = 153,
    [492] = 185,
    [493] = 185,
    [494] = 183,
    [495] = 132,
    [496] = 153,
    [497] = 183,
    [498] = 183,
    [499] = 128,
    [500] = 164,
    [501] = 128,
    [502] = 104,
    [503] = 104,
    [504] = 186,
    [505] = 187,
    [506] = 104,
    [507] = 104,
    [508] = 128,
    [509] = 128,
    [510] = 165,
    [511] = 104,
    [512] = 187,
    [513] = 128,
    [514] = 104,
    [515] = 186,
    [516] = 165,
    [517] = 103,
    [518] = 129,
    [519] = 103,
    [520] = 129,
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

static unsigned short ts_parse_table[STATE_COUNT][SYMBOL_COUNT] = {
    [0] = {
        [sym_source_file] = 2,
        [sym_package_clause] = 4,
        [anon_sym_package] = 6,
        [sym_comment] = 8,
    },
    [1] = {
        [ts_builtin_sym_end] = 10,
        [sym_comment] = 8,
    },
    [2] = {
        [sym_import_declaration] = 12,
        [sym__top_level_declaration] = 14,
        [sym__declaration] = 16,
        [sym_const_declaration] = 18,
        [sym_var_declaration] = 18,
        [sym_function_declaration] = 16,
        [sym_method_declaration] = 16,
        [sym_type_declaration] = 18,
        [aux_sym_source_file_repeat1] = 20,
        [aux_sym_source_file_repeat2] = 22,
        [ts_builtin_sym_end] = 24,
        [anon_sym_import] = 26,
        [anon_sym_const] = 28,
        [anon_sym_var] = 30,
        [anon_sym_func] = 32,
        [anon_sym_type] = 34,
        [sym_comment] = 8,
    },
    [3] = {
        [sym_identifier] = 36,
        [sym_comment] = 8,
    },
    [4] = {
        [sym_import_declaration] = 38,
        [sym__top_level_declaration] = 38,
        [sym__declaration] = 38,
        [sym_const_declaration] = 38,
        [sym_var_declaration] = 38,
        [sym_function_declaration] = 38,
        [sym_method_declaration] = 38,
        [sym_type_declaration] = 38,
        [aux_sym_source_file_repeat1] = 38,
        [aux_sym_source_file_repeat2] = 38,
        [ts_builtin_sym_end] = 38,
        [anon_sym_import] = 38,
        [anon_sym_const] = 38,
        [anon_sym_var] = 38,
        [anon_sym_func] = 38,
        [anon_sym_type] = 38,
        [sym_comment] = 8,
    },
    [5] = {
        [sym_import_declaration] = 12,
        [sym__top_level_declaration] = 40,
        [sym__declaration] = 40,
        [sym_const_declaration] = 40,
        [sym_var_declaration] = 40,
        [sym_function_declaration] = 40,
        [sym_method_declaration] = 40,
        [sym_type_declaration] = 40,
        [aux_sym_source_file_repeat1] = 42,
        [aux_sym_source_file_repeat2] = 40,
        [ts_builtin_sym_end] = 40,
        [anon_sym_import] = 26,
        [anon_sym_const] = 40,
        [anon_sym_var] = 40,
        [anon_sym_func] = 40,
        [anon_sym_type] = 40,
        [sym_comment] = 8,
    },
    [6] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 44,
        [sym_comment] = 8,
    },
    [7] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 46,
        [sym_comment] = 8,
    },
    [8] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 48,
        [sym_comment] = 8,
    },
    [9] = {
        [sym__top_level_declaration] = 14,
        [sym__declaration] = 16,
        [sym_const_declaration] = 18,
        [sym_var_declaration] = 18,
        [sym_function_declaration] = 16,
        [sym_method_declaration] = 16,
        [sym_type_declaration] = 18,
        [aux_sym_source_file_repeat2] = 50,
        [ts_builtin_sym_end] = 52,
        [anon_sym_const] = 28,
        [anon_sym_var] = 30,
        [anon_sym_func] = 32,
        [anon_sym_type] = 34,
        [sym_comment] = 8,
    },
    [10] = {
        [ts_builtin_sym_end] = 52,
        [sym_comment] = 8,
    },
    [11] = {
        [sym_import_spec] = 54,
        [sym__string_literal] = 56,
        [anon_sym_LPAREN] = 58,
        [anon_sym_DOT] = 60,
        [sym_identifier] = 60,
        [sym_raw_string_literal] = 62,
        [sym_interpreted_string_literal] = 62,
        [sym_comment] = 8,
    },
    [12] = {
        [sym_const_spec] = 64,
        [sym_identifier_list] = 66,
        [anon_sym_LPAREN] = 68,
        [sym_identifier] = 70,
        [sym_comment] = 8,
    },
    [13] = {
        [sym_var_spec] = 72,
        [sym_identifier_list] = 74,
        [anon_sym_LPAREN] = 76,
        [sym_identifier] = 70,
        [sym_comment] = 8,
    },
    [14] = {
        [sym_parameters] = 78,
        [anon_sym_LPAREN] = 80,
        [sym_identifier] = 82,
        [sym_comment] = 8,
    },
    [15] = {
        [sym_type_spec] = 84,
        [anon_sym_LPAREN] = 86,
        [sym_identifier] = 88,
        [sym_comment] = 8,
    },
    [16] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 90,
        [sym_comment] = 8,
    },
    [17] = {
        [sym_type_spec] = 92,
        [aux_sym_type_declaration_repeat1] = 94,
        [anon_sym_RPAREN] = 96,
        [sym_identifier] = 88,
        [sym_comment] = 8,
    },
    [18] = {
        [sym__type] = 98,
        [sym_pointer_type] = 100,
        [sym_array_type] = 100,
        [sym_slice_type] = 100,
        [sym_struct_type] = 100,
        [sym_interface_type] = 100,
        [sym_map_type] = 100,
        [sym_channel_type] = 100,
        [sym_function_type] = 100,
        [sym_qualified_identifier] = 100,
        [anon_sym_func] = 102,
        [anon_sym_STAR] = 104,
        [anon_sym_LBRACK] = 106,
        [anon_sym_struct] = 108,
        [anon_sym_interface] = 110,
        [anon_sym_map] = 112,
        [anon_sym_chan] = 114,
        [anon_sym_LT_DASH] = 116,
        [sym_identifier] = 118,
        [sym_comment] = 8,
    },
    [19] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 120,
        [sym_comment] = 8,
    },
    [20] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 122,
        [sym_comment] = 8,
    },
    [21] = {
        [sym_parameters] = 124,
        [anon_sym_LPAREN] = 126,
        [sym_comment] = 8,
    },
    [22] = {
        [sym__type] = 128,
        [sym_pointer_type] = 100,
        [sym_array_type] = 100,
        [sym_slice_type] = 100,
        [sym_struct_type] = 100,
        [sym_interface_type] = 100,
        [sym_map_type] = 100,
        [sym_channel_type] = 100,
        [sym_function_type] = 100,
        [sym_qualified_identifier] = 100,
        [anon_sym_func] = 102,
        [anon_sym_STAR] = 104,
        [anon_sym_LBRACK] = 106,
        [anon_sym_struct] = 108,
        [anon_sym_interface] = 110,
        [anon_sym_map] = 112,
        [anon_sym_chan] = 114,
        [anon_sym_LT_DASH] = 116,
        [sym_identifier] = 118,
        [sym_comment] = 8,
    },
    [23] = {
        [sym__expression] = 130,
        [sym_call_expression] = 132,
        [sym_unary_expression] = 132,
        [sym_binary_expression] = 132,
        [sym__primary_expression] = 132,
        [sym__string_literal] = 134,
        [sym_int_literal] = 134,
        [sym_float_literal] = 134,
        [anon_sym_RBRACK] = 136,
        [sym_identifier] = 134,
        [sym_raw_string_literal] = 138,
        [sym_interpreted_string_literal] = 138,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 140,
        [sym_comment] = 8,
    },
    [24] = {
        [anon_sym_LBRACE] = 142,
        [sym_comment] = 8,
    },
    [25] = {
        [anon_sym_LBRACE] = 144,
        [sym_comment] = 8,
    },
    [26] = {
        [anon_sym_LBRACK] = 146,
        [sym_comment] = 8,
    },
    [27] = {
        [sym__type] = 148,
        [sym_pointer_type] = 100,
        [sym_array_type] = 100,
        [sym_slice_type] = 100,
        [sym_struct_type] = 100,
        [sym_interface_type] = 100,
        [sym_map_type] = 100,
        [sym_channel_type] = 100,
        [sym_function_type] = 100,
        [sym_qualified_identifier] = 100,
        [anon_sym_func] = 102,
        [anon_sym_STAR] = 104,
        [anon_sym_LBRACK] = 106,
        [anon_sym_struct] = 108,
        [anon_sym_interface] = 110,
        [anon_sym_map] = 112,
        [anon_sym_chan] = 114,
        [anon_sym_LT_DASH] = 150,
        [sym_identifier] = 118,
        [sym_comment] = 8,
    },
    [28] = {
        [anon_sym_chan] = 152,
        [sym_comment] = 8,
    },
    [29] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 122,
        [anon_sym_DOT] = 154,
        [sym_comment] = 8,
    },
    [30] = {
        [sym_identifier] = 156,
        [sym_comment] = 8,
    },
    [31] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 158,
        [sym_comment] = 8,
    },
    [32] = {
        [sym__type] = 160,
        [sym_pointer_type] = 100,
        [sym_array_type] = 100,
        [sym_slice_type] = 100,
        [sym_struct_type] = 100,
        [sym_interface_type] = 100,
        [sym_map_type] = 100,
        [sym_channel_type] = 100,
        [sym_function_type] = 100,
        [sym_qualified_identifier] = 100,
        [anon_sym_func] = 102,
        [anon_sym_STAR] = 104,
        [anon_sym_LBRACK] = 106,
        [anon_sym_struct] = 108,
        [anon_sym_interface] = 110,
        [anon_sym_map] = 112,
        [anon_sym_chan] = 114,
        [anon_sym_LT_DASH] = 116,
        [sym_identifier] = 118,
        [sym_comment] = 8,
    },
    [33] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 162,
        [sym_comment] = 8,
    },
    [34] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 164,
        [sym_comment] = 8,
    },
    [35] = {
        [sym__type] = 166,
        [sym_pointer_type] = 100,
        [sym_array_type] = 100,
        [sym_slice_type] = 100,
        [sym_struct_type] = 100,
        [sym_interface_type] = 100,
        [sym_map_type] = 100,
        [sym_channel_type] = 100,
        [sym_function_type] = 100,
        [sym_qualified_identifier] = 100,
        [anon_sym_func] = 102,
        [anon_sym_STAR] = 104,
        [anon_sym_LBRACK] = 106,
        [anon_sym_struct] = 108,
        [anon_sym_interface] = 110,
        [anon_sym_map] = 112,
        [anon_sym_chan] = 114,
        [anon_sym_LT_DASH] = 116,
        [sym_identifier] = 118,
        [sym_comment] = 8,
    },
    [36] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 168,
        [sym_comment] = 8,
    },
    [37] = {
        [sym__type] = 170,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [38] = {
        [anon_sym_RBRACK] = 192,
        [sym_comment] = 8,
    },
    [39] = {
        [anon_sym_RBRACK] = 122,
        [sym_comment] = 8,
    },
    [40] = {
        [sym_parameters] = 194,
        [anon_sym_LPAREN] = 196,
        [sym_comment] = 8,
    },
    [41] = {
        [sym__type] = 198,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [42] = {
        [sym__expression] = 200,
        [sym_call_expression] = 132,
        [sym_unary_expression] = 132,
        [sym_binary_expression] = 132,
        [sym__primary_expression] = 132,
        [sym__string_literal] = 134,
        [sym_int_literal] = 134,
        [sym_float_literal] = 134,
        [anon_sym_RBRACK] = 202,
        [sym_identifier] = 134,
        [sym_raw_string_literal] = 138,
        [sym_interpreted_string_literal] = 138,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 140,
        [sym_comment] = 8,
    },
    [43] = {
        [anon_sym_LBRACE] = 204,
        [sym_comment] = 8,
    },
    [44] = {
        [anon_sym_LBRACE] = 206,
        [sym_comment] = 8,
    },
    [45] = {
        [anon_sym_LBRACK] = 208,
        [sym_comment] = 8,
    },
    [46] = {
        [sym__type] = 210,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 212,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [47] = {
        [anon_sym_chan] = 214,
        [sym_comment] = 8,
    },
    [48] = {
        [anon_sym_DOT] = 216,
        [anon_sym_RBRACK] = 122,
        [sym_comment] = 8,
    },
    [49] = {
        [sym_identifier] = 218,
        [sym_comment] = 8,
    },
    [50] = {
        [anon_sym_RBRACK] = 158,
        [sym_comment] = 8,
    },
    [51] = {
        [sym__type] = 220,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [52] = {
        [anon_sym_RBRACK] = 162,
        [sym_comment] = 8,
    },
    [53] = {
        [anon_sym_RBRACK] = 164,
        [sym_comment] = 8,
    },
    [54] = {
        [sym__type] = 222,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [55] = {
        [anon_sym_RBRACK] = 168,
        [sym_comment] = 8,
    },
    [56] = {
        [sym__type] = 224,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [57] = {
        [anon_sym_RBRACK] = 226,
        [sym_comment] = 8,
    },
    [58] = {
        [sym__type] = 228,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [59] = {
        [anon_sym_RBRACK] = 230,
        [sym_comment] = 8,
    },
    [60] = {
        [sym_method_spec] = 232,
        [aux_sym_interface_type_repeat1] = 234,
        [anon_sym_RBRACE] = 236,
        [sym_identifier] = 238,
        [sym_comment] = 8,
    },
    [61] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 240,
        [sym_comment] = 8,
    },
    [62] = {
        [anon_sym_RBRACE] = 242,
        [sym_comment] = 8,
    },
    [63] = {
        [anon_sym_RBRACK] = 244,
        [sym_comment] = 8,
    },
    [64] = {
        [sym_parameters] = 246,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 240,
        [anon_sym_LPAREN] = 126,
        [sym_comment] = 8,
    },
    [65] = {
        [sym_parameters] = 248,
        [sym__type] = 248,
        [sym_pointer_type] = 100,
        [sym_array_type] = 100,
        [sym_slice_type] = 100,
        [sym_struct_type] = 100,
        [sym_interface_type] = 100,
        [sym_map_type] = 100,
        [sym_channel_type] = 100,
        [sym_function_type] = 100,
        [sym_qualified_identifier] = 100,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 250,
        [anon_sym_LPAREN] = 252,
        [anon_sym_func] = 102,
        [anon_sym_STAR] = 104,
        [anon_sym_LBRACK] = 106,
        [anon_sym_struct] = 108,
        [anon_sym_interface] = 110,
        [anon_sym_map] = 112,
        [anon_sym_chan] = 114,
        [anon_sym_LT_DASH] = 116,
        [sym_identifier] = 118,
        [sym_comment] = 8,
    },
    [66] = {
        [sym_method_spec] = 232,
        [aux_sym_interface_type_repeat1] = 254,
        [anon_sym_RBRACE] = 256,
        [sym_identifier] = 238,
        [sym_comment] = 8,
    },
    [67] = {
        [sym__parameter_list] = 258,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 262,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [68] = {
        [anon_sym_RPAREN] = 266,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [69] = {
        [anon_sym_RPAREN] = 270,
        [anon_sym_COMMA] = 270,
        [sym_comment] = 8,
    },
    [70] = {
        [sym_parameters] = 272,
        [sym__type] = 272,
        [sym_pointer_type] = 272,
        [sym_array_type] = 272,
        [sym_slice_type] = 272,
        [sym_struct_type] = 272,
        [sym_interface_type] = 272,
        [sym_map_type] = 272,
        [sym_channel_type] = 272,
        [sym_function_type] = 272,
        [sym_qualified_identifier] = 272,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 272,
        [anon_sym_LPAREN] = 272,
        [anon_sym_func] = 272,
        [anon_sym_STAR] = 272,
        [anon_sym_LBRACK] = 272,
        [anon_sym_struct] = 272,
        [anon_sym_interface] = 272,
        [anon_sym_map] = 272,
        [anon_sym_chan] = 272,
        [anon_sym_LT_DASH] = 272,
        [sym_identifier] = 272,
        [sym_comment] = 8,
    },
    [71] = {
        [sym__type] = 274,
        [sym_pointer_type] = 276,
        [sym_array_type] = 276,
        [sym_slice_type] = 276,
        [sym_struct_type] = 276,
        [sym_interface_type] = 276,
        [sym_map_type] = 276,
        [sym_channel_type] = 276,
        [sym_function_type] = 276,
        [sym_qualified_identifier] = 276,
        [anon_sym_RPAREN] = 270,
        [anon_sym_func] = 278,
        [anon_sym_COMMA] = 270,
        [anon_sym_STAR] = 280,
        [anon_sym_LBRACK] = 282,
        [anon_sym_struct] = 284,
        [anon_sym_interface] = 286,
        [anon_sym_map] = 288,
        [anon_sym_chan] = 290,
        [anon_sym_LT_DASH] = 292,
        [sym_identifier] = 294,
        [sym_comment] = 8,
    },
    [72] = {
        [anon_sym_RPAREN] = 296,
        [anon_sym_COMMA] = 296,
        [sym_comment] = 8,
    },
    [73] = {
        [anon_sym_RPAREN] = 122,
        [anon_sym_COMMA] = 122,
        [sym_comment] = 8,
    },
    [74] = {
        [sym_parameters] = 298,
        [anon_sym_LPAREN] = 300,
        [sym_comment] = 8,
    },
    [75] = {
        [sym__type] = 302,
        [sym_pointer_type] = 276,
        [sym_array_type] = 276,
        [sym_slice_type] = 276,
        [sym_struct_type] = 276,
        [sym_interface_type] = 276,
        [sym_map_type] = 276,
        [sym_channel_type] = 276,
        [sym_function_type] = 276,
        [sym_qualified_identifier] = 276,
        [anon_sym_func] = 278,
        [anon_sym_STAR] = 280,
        [anon_sym_LBRACK] = 282,
        [anon_sym_struct] = 284,
        [anon_sym_interface] = 286,
        [anon_sym_map] = 288,
        [anon_sym_chan] = 290,
        [anon_sym_LT_DASH] = 292,
        [sym_identifier] = 294,
        [sym_comment] = 8,
    },
    [76] = {
        [sym__expression] = 304,
        [sym_call_expression] = 132,
        [sym_unary_expression] = 132,
        [sym_binary_expression] = 132,
        [sym__primary_expression] = 132,
        [sym__string_literal] = 134,
        [sym_int_literal] = 134,
        [sym_float_literal] = 134,
        [anon_sym_RBRACK] = 306,
        [sym_identifier] = 134,
        [sym_raw_string_literal] = 138,
        [sym_interpreted_string_literal] = 138,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 140,
        [sym_comment] = 8,
    },
    [77] = {
        [anon_sym_LBRACE] = 308,
        [sym_comment] = 8,
    },
    [78] = {
        [anon_sym_LBRACE] = 310,
        [sym_comment] = 8,
    },
    [79] = {
        [anon_sym_LBRACK] = 312,
        [sym_comment] = 8,
    },
    [80] = {
        [sym__type] = 314,
        [sym_pointer_type] = 276,
        [sym_array_type] = 276,
        [sym_slice_type] = 276,
        [sym_struct_type] = 276,
        [sym_interface_type] = 276,
        [sym_map_type] = 276,
        [sym_channel_type] = 276,
        [sym_function_type] = 276,
        [sym_qualified_identifier] = 276,
        [anon_sym_func] = 278,
        [anon_sym_STAR] = 280,
        [anon_sym_LBRACK] = 282,
        [anon_sym_struct] = 284,
        [anon_sym_interface] = 286,
        [anon_sym_map] = 288,
        [anon_sym_chan] = 290,
        [anon_sym_LT_DASH] = 316,
        [sym_identifier] = 294,
        [sym_comment] = 8,
    },
    [81] = {
        [anon_sym_chan] = 318,
        [sym_comment] = 8,
    },
    [82] = {
        [anon_sym_RPAREN] = 122,
        [anon_sym_DOT] = 320,
        [anon_sym_COMMA] = 122,
        [sym_comment] = 8,
    },
    [83] = {
        [sym_identifier] = 322,
        [sym_comment] = 8,
    },
    [84] = {
        [anon_sym_RPAREN] = 158,
        [anon_sym_COMMA] = 158,
        [sym_comment] = 8,
    },
    [85] = {
        [sym__type] = 324,
        [sym_pointer_type] = 276,
        [sym_array_type] = 276,
        [sym_slice_type] = 276,
        [sym_struct_type] = 276,
        [sym_interface_type] = 276,
        [sym_map_type] = 276,
        [sym_channel_type] = 276,
        [sym_function_type] = 276,
        [sym_qualified_identifier] = 276,
        [anon_sym_func] = 278,
        [anon_sym_STAR] = 280,
        [anon_sym_LBRACK] = 282,
        [anon_sym_struct] = 284,
        [anon_sym_interface] = 286,
        [anon_sym_map] = 288,
        [anon_sym_chan] = 290,
        [anon_sym_LT_DASH] = 292,
        [sym_identifier] = 294,
        [sym_comment] = 8,
    },
    [86] = {
        [anon_sym_RPAREN] = 162,
        [anon_sym_COMMA] = 162,
        [sym_comment] = 8,
    },
    [87] = {
        [anon_sym_RPAREN] = 164,
        [anon_sym_COMMA] = 164,
        [sym_comment] = 8,
    },
    [88] = {
        [sym__type] = 326,
        [sym_pointer_type] = 276,
        [sym_array_type] = 276,
        [sym_slice_type] = 276,
        [sym_struct_type] = 276,
        [sym_interface_type] = 276,
        [sym_map_type] = 276,
        [sym_channel_type] = 276,
        [sym_function_type] = 276,
        [sym_qualified_identifier] = 276,
        [anon_sym_func] = 278,
        [anon_sym_STAR] = 280,
        [anon_sym_LBRACK] = 282,
        [anon_sym_struct] = 284,
        [anon_sym_interface] = 286,
        [anon_sym_map] = 288,
        [anon_sym_chan] = 290,
        [anon_sym_LT_DASH] = 292,
        [sym_identifier] = 294,
        [sym_comment] = 8,
    },
    [89] = {
        [anon_sym_RPAREN] = 168,
        [anon_sym_COMMA] = 168,
        [sym_comment] = 8,
    },
    [90] = {
        [sym__type] = 328,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [91] = {
        [anon_sym_RBRACK] = 330,
        [sym_comment] = 8,
    },
    [92] = {
        [sym__type] = 332,
        [sym_pointer_type] = 276,
        [sym_array_type] = 276,
        [sym_slice_type] = 276,
        [sym_struct_type] = 276,
        [sym_interface_type] = 276,
        [sym_map_type] = 276,
        [sym_channel_type] = 276,
        [sym_function_type] = 276,
        [sym_qualified_identifier] = 276,
        [anon_sym_func] = 278,
        [anon_sym_STAR] = 280,
        [anon_sym_LBRACK] = 282,
        [anon_sym_struct] = 284,
        [anon_sym_interface] = 286,
        [anon_sym_map] = 288,
        [anon_sym_chan] = 290,
        [anon_sym_LT_DASH] = 292,
        [sym_identifier] = 294,
        [sym_comment] = 8,
    },
    [93] = {
        [anon_sym_RPAREN] = 230,
        [anon_sym_COMMA] = 230,
        [sym_comment] = 8,
    },
    [94] = {
        [sym_method_spec] = 232,
        [aux_sym_interface_type_repeat1] = 334,
        [anon_sym_RBRACE] = 336,
        [sym_identifier] = 238,
        [sym_comment] = 8,
    },
    [95] = {
        [anon_sym_RBRACE] = 338,
        [sym_comment] = 8,
    },
    [96] = {
        [anon_sym_RPAREN] = 244,
        [anon_sym_COMMA] = 244,
        [sym_comment] = 8,
    },
    [97] = {
        [anon_sym_RPAREN] = 340,
        [anon_sym_COMMA] = 340,
        [sym_comment] = 8,
    },
    [98] = {
        [sym_identifier_list] = 342,
        [sym_field_declaration] = 344,
        [aux_sym_struct_type_repeat1] = 346,
        [anon_sym_STAR] = 348,
        [anon_sym_RBRACE] = 350,
        [sym_identifier] = 352,
        [sym_comment] = 8,
    },
    [99] = {
        [sym__type] = 354,
        [sym_pointer_type] = 356,
        [sym_array_type] = 356,
        [sym_slice_type] = 356,
        [sym_struct_type] = 356,
        [sym_interface_type] = 356,
        [sym_map_type] = 356,
        [sym_channel_type] = 356,
        [sym_function_type] = 356,
        [sym_qualified_identifier] = 356,
        [anon_sym_func] = 358,
        [anon_sym_STAR] = 360,
        [anon_sym_LBRACK] = 362,
        [anon_sym_struct] = 364,
        [anon_sym_interface] = 366,
        [anon_sym_map] = 368,
        [anon_sym_chan] = 370,
        [anon_sym_LT_DASH] = 372,
        [sym_identifier] = 374,
        [sym_comment] = 8,
    },
    [100] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 376,
        [sym_comment] = 8,
    },
    [101] = {
        [anon_sym_RBRACE] = 378,
        [sym_comment] = 8,
    },
    [102] = {
        [sym_identifier] = 354,
        [sym_comment] = 8,
    },
    [103] = {
        [anon_sym_RPAREN] = 380,
        [anon_sym_COMMA] = 380,
        [sym_comment] = 8,
    },
    [104] = {
        [sym__type] = 382,
        [sym_pointer_type] = 382,
        [sym_array_type] = 382,
        [sym_slice_type] = 382,
        [sym_struct_type] = 382,
        [sym_interface_type] = 382,
        [sym_map_type] = 382,
        [sym_channel_type] = 382,
        [sym_function_type] = 382,
        [sym_qualified_identifier] = 382,
        [sym__string_literal] = 384,
        [aux_sym_identifier_list_repeat1] = 386,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 388,
        [anon_sym_func] = 382,
        [anon_sym_COMMA] = 390,
        [anon_sym_STAR] = 382,
        [anon_sym_LBRACK] = 382,
        [anon_sym_struct] = 382,
        [anon_sym_interface] = 382,
        [anon_sym_map] = 382,
        [anon_sym_chan] = 382,
        [anon_sym_LT_DASH] = 382,
        [sym_identifier] = 382,
        [sym_raw_string_literal] = 392,
        [sym_interpreted_string_literal] = 392,
        [sym_comment] = 8,
    },
    [105] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 394,
        [sym_comment] = 8,
    },
    [106] = {
        [sym__type] = 396,
        [sym_pointer_type] = 396,
        [sym_array_type] = 396,
        [sym_slice_type] = 396,
        [sym_struct_type] = 396,
        [sym_interface_type] = 396,
        [sym_map_type] = 396,
        [sym_channel_type] = 396,
        [sym_function_type] = 396,
        [sym_qualified_identifier] = 396,
        [anon_sym_func] = 396,
        [anon_sym_STAR] = 396,
        [anon_sym_LBRACK] = 396,
        [anon_sym_struct] = 396,
        [anon_sym_interface] = 396,
        [anon_sym_map] = 396,
        [anon_sym_chan] = 396,
        [anon_sym_LT_DASH] = 396,
        [sym_identifier] = 396,
        [sym_comment] = 8,
    },
    [107] = {
        [sym_identifier] = 398,
        [sym_comment] = 8,
    },
    [108] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 400,
        [sym_comment] = 8,
    },
    [109] = {
        [sym__type] = 402,
        [sym_pointer_type] = 402,
        [sym_array_type] = 402,
        [sym_slice_type] = 402,
        [sym_struct_type] = 402,
        [sym_interface_type] = 402,
        [sym_map_type] = 402,
        [sym_channel_type] = 402,
        [sym_function_type] = 402,
        [sym_qualified_identifier] = 402,
        [aux_sym_identifier_list_repeat1] = 404,
        [anon_sym_func] = 402,
        [anon_sym_COMMA] = 390,
        [anon_sym_STAR] = 402,
        [anon_sym_LBRACK] = 402,
        [anon_sym_struct] = 402,
        [anon_sym_interface] = 402,
        [anon_sym_map] = 402,
        [anon_sym_chan] = 402,
        [anon_sym_LT_DASH] = 402,
        [sym_identifier] = 402,
        [sym_comment] = 8,
    },
    [110] = {
        [sym__type] = 406,
        [sym_pointer_type] = 406,
        [sym_array_type] = 406,
        [sym_slice_type] = 406,
        [sym_struct_type] = 406,
        [sym_interface_type] = 406,
        [sym_map_type] = 406,
        [sym_channel_type] = 406,
        [sym_function_type] = 406,
        [sym_qualified_identifier] = 406,
        [anon_sym_func] = 406,
        [anon_sym_STAR] = 406,
        [anon_sym_LBRACK] = 406,
        [anon_sym_struct] = 406,
        [anon_sym_interface] = 406,
        [anon_sym_map] = 406,
        [anon_sym_chan] = 406,
        [anon_sym_LT_DASH] = 406,
        [sym_identifier] = 406,
        [sym_comment] = 8,
    },
    [111] = {
        [sym__string_literal] = 408,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 394,
        [sym_raw_string_literal] = 392,
        [sym_interpreted_string_literal] = 392,
        [sym_comment] = 8,
    },
    [112] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 410,
        [sym_comment] = 8,
    },
    [113] = {
        [anon_sym_RPAREN] = 412,
        [anon_sym_COMMA] = 412,
        [sym_comment] = 8,
    },
    [114] = {
        [sym_identifier_list] = 342,
        [sym_field_declaration] = 344,
        [aux_sym_struct_type_repeat1] = 414,
        [anon_sym_STAR] = 348,
        [anon_sym_RBRACE] = 416,
        [sym_identifier] = 352,
        [sym_comment] = 8,
    },
    [115] = {
        [anon_sym_RBRACE] = 418,
        [sym_comment] = 8,
    },
    [116] = {
        [sym__string_literal] = 122,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 122,
        [sym_raw_string_literal] = 122,
        [sym_interpreted_string_literal] = 122,
        [sym_comment] = 8,
    },
    [117] = {
        [sym_parameters] = 420,
        [anon_sym_LPAREN] = 422,
        [sym_comment] = 8,
    },
    [118] = {
        [sym__type] = 424,
        [sym_pointer_type] = 356,
        [sym_array_type] = 356,
        [sym_slice_type] = 356,
        [sym_struct_type] = 356,
        [sym_interface_type] = 356,
        [sym_map_type] = 356,
        [sym_channel_type] = 356,
        [sym_function_type] = 356,
        [sym_qualified_identifier] = 356,
        [anon_sym_func] = 358,
        [anon_sym_STAR] = 360,
        [anon_sym_LBRACK] = 362,
        [anon_sym_struct] = 364,
        [anon_sym_interface] = 366,
        [anon_sym_map] = 368,
        [anon_sym_chan] = 370,
        [anon_sym_LT_DASH] = 372,
        [sym_identifier] = 374,
        [sym_comment] = 8,
    },
    [119] = {
        [sym__expression] = 426,
        [sym_call_expression] = 132,
        [sym_unary_expression] = 132,
        [sym_binary_expression] = 132,
        [sym__primary_expression] = 132,
        [sym__string_literal] = 134,
        [sym_int_literal] = 134,
        [sym_float_literal] = 134,
        [anon_sym_RBRACK] = 428,
        [sym_identifier] = 134,
        [sym_raw_string_literal] = 138,
        [sym_interpreted_string_literal] = 138,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 140,
        [sym_comment] = 8,
    },
    [120] = {
        [anon_sym_LBRACE] = 430,
        [sym_comment] = 8,
    },
    [121] = {
        [anon_sym_LBRACE] = 432,
        [sym_comment] = 8,
    },
    [122] = {
        [anon_sym_LBRACK] = 434,
        [sym_comment] = 8,
    },
    [123] = {
        [sym__type] = 436,
        [sym_pointer_type] = 356,
        [sym_array_type] = 356,
        [sym_slice_type] = 356,
        [sym_struct_type] = 356,
        [sym_interface_type] = 356,
        [sym_map_type] = 356,
        [sym_channel_type] = 356,
        [sym_function_type] = 356,
        [sym_qualified_identifier] = 356,
        [anon_sym_func] = 358,
        [anon_sym_STAR] = 360,
        [anon_sym_LBRACK] = 362,
        [anon_sym_struct] = 364,
        [anon_sym_interface] = 366,
        [anon_sym_map] = 368,
        [anon_sym_chan] = 370,
        [anon_sym_LT_DASH] = 438,
        [sym_identifier] = 374,
        [sym_comment] = 8,
    },
    [124] = {
        [anon_sym_chan] = 440,
        [sym_comment] = 8,
    },
    [125] = {
        [sym__string_literal] = 122,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 122,
        [anon_sym_DOT] = 442,
        [sym_raw_string_literal] = 122,
        [sym_interpreted_string_literal] = 122,
        [sym_comment] = 8,
    },
    [126] = {
        [sym_identifier] = 444,
        [sym_comment] = 8,
    },
    [127] = {
        [sym__string_literal] = 158,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 158,
        [sym_raw_string_literal] = 158,
        [sym_interpreted_string_literal] = 158,
        [sym_comment] = 8,
    },
    [128] = {
        [sym__type] = 446,
        [sym_pointer_type] = 356,
        [sym_array_type] = 356,
        [sym_slice_type] = 356,
        [sym_struct_type] = 356,
        [sym_interface_type] = 356,
        [sym_map_type] = 356,
        [sym_channel_type] = 356,
        [sym_function_type] = 356,
        [sym_qualified_identifier] = 356,
        [anon_sym_func] = 358,
        [anon_sym_STAR] = 360,
        [anon_sym_LBRACK] = 362,
        [anon_sym_struct] = 364,
        [anon_sym_interface] = 366,
        [anon_sym_map] = 368,
        [anon_sym_chan] = 370,
        [anon_sym_LT_DASH] = 372,
        [sym_identifier] = 374,
        [sym_comment] = 8,
    },
    [129] = {
        [sym__string_literal] = 162,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 162,
        [sym_raw_string_literal] = 162,
        [sym_interpreted_string_literal] = 162,
        [sym_comment] = 8,
    },
    [130] = {
        [sym__string_literal] = 164,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 164,
        [sym_raw_string_literal] = 164,
        [sym_interpreted_string_literal] = 164,
        [sym_comment] = 8,
    },
    [131] = {
        [sym__type] = 448,
        [sym_pointer_type] = 356,
        [sym_array_type] = 356,
        [sym_slice_type] = 356,
        [sym_struct_type] = 356,
        [sym_interface_type] = 356,
        [sym_map_type] = 356,
        [sym_channel_type] = 356,
        [sym_function_type] = 356,
        [sym_qualified_identifier] = 356,
        [anon_sym_func] = 358,
        [anon_sym_STAR] = 360,
        [anon_sym_LBRACK] = 362,
        [anon_sym_struct] = 364,
        [anon_sym_interface] = 366,
        [anon_sym_map] = 368,
        [anon_sym_chan] = 370,
        [anon_sym_LT_DASH] = 372,
        [sym_identifier] = 374,
        [sym_comment] = 8,
    },
    [132] = {
        [sym__string_literal] = 168,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 168,
        [sym_raw_string_literal] = 168,
        [sym_interpreted_string_literal] = 168,
        [sym_comment] = 8,
    },
    [133] = {
        [sym__type] = 450,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [134] = {
        [anon_sym_RBRACK] = 452,
        [sym_comment] = 8,
    },
    [135] = {
        [sym__type] = 454,
        [sym_pointer_type] = 356,
        [sym_array_type] = 356,
        [sym_slice_type] = 356,
        [sym_struct_type] = 356,
        [sym_interface_type] = 356,
        [sym_map_type] = 356,
        [sym_channel_type] = 356,
        [sym_function_type] = 356,
        [sym_qualified_identifier] = 356,
        [anon_sym_func] = 358,
        [anon_sym_STAR] = 360,
        [anon_sym_LBRACK] = 362,
        [anon_sym_struct] = 364,
        [anon_sym_interface] = 366,
        [anon_sym_map] = 368,
        [anon_sym_chan] = 370,
        [anon_sym_LT_DASH] = 372,
        [sym_identifier] = 374,
        [sym_comment] = 8,
    },
    [136] = {
        [sym__string_literal] = 230,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 230,
        [sym_raw_string_literal] = 230,
        [sym_interpreted_string_literal] = 230,
        [sym_comment] = 8,
    },
    [137] = {
        [sym_method_spec] = 232,
        [aux_sym_interface_type_repeat1] = 456,
        [anon_sym_RBRACE] = 458,
        [sym_identifier] = 238,
        [sym_comment] = 8,
    },
    [138] = {
        [anon_sym_RBRACE] = 460,
        [sym_comment] = 8,
    },
    [139] = {
        [sym__string_literal] = 244,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 244,
        [sym_raw_string_literal] = 244,
        [sym_interpreted_string_literal] = 244,
        [sym_comment] = 8,
    },
    [140] = {
        [sym__string_literal] = 340,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 340,
        [sym_raw_string_literal] = 340,
        [sym_interpreted_string_literal] = 340,
        [sym_comment] = 8,
    },
    [141] = {
        [sym_identifier_list] = 342,
        [sym_field_declaration] = 344,
        [aux_sym_struct_type_repeat1] = 462,
        [anon_sym_STAR] = 348,
        [anon_sym_RBRACE] = 464,
        [sym_identifier] = 352,
        [sym_comment] = 8,
    },
    [142] = {
        [anon_sym_RBRACE] = 466,
        [sym_comment] = 8,
    },
    [143] = {
        [sym__string_literal] = 380,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 380,
        [sym_raw_string_literal] = 380,
        [sym_interpreted_string_literal] = 380,
        [sym_comment] = 8,
    },
    [144] = {
        [sym__string_literal] = 412,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 412,
        [sym_raw_string_literal] = 412,
        [sym_interpreted_string_literal] = 412,
        [sym_comment] = 8,
    },
    [145] = {
        [anon_sym_LPAREN] = 468,
        [anon_sym_STAR] = 470,
        [anon_sym_RBRACK] = 472,
        [anon_sym_SLASH] = 470,
        [anon_sym_PERCENT] = 470,
        [anon_sym_LT_LT] = 470,
        [anon_sym_GT_GT] = 470,
        [anon_sym_AMP] = 470,
        [anon_sym_AMP_CARET] = 470,
        [anon_sym_PLUS] = 474,
        [anon_sym_DASH] = 474,
        [anon_sym_PIPE] = 474,
        [anon_sym_CARET] = 474,
        [anon_sym_EQ_EQ] = 476,
        [anon_sym_BANG_EQ] = 476,
        [anon_sym_LT] = 476,
        [anon_sym_LT_EQ] = 476,
        [anon_sym_GT] = 476,
        [anon_sym_GT_EQ] = 476,
        [anon_sym_AMP_AMP] = 478,
        [anon_sym_PIPE_PIPE] = 480,
        [sym_comment] = 8,
    },
    [146] = {
        [anon_sym_LPAREN] = 482,
        [anon_sym_STAR] = 482,
        [anon_sym_RBRACK] = 482,
        [anon_sym_SLASH] = 482,
        [anon_sym_PERCENT] = 482,
        [anon_sym_LT_LT] = 482,
        [anon_sym_GT_GT] = 482,
        [anon_sym_AMP] = 482,
        [anon_sym_AMP_CARET] = 482,
        [anon_sym_PLUS] = 482,
        [anon_sym_DASH] = 482,
        [anon_sym_PIPE] = 482,
        [anon_sym_CARET] = 482,
        [anon_sym_EQ_EQ] = 482,
        [anon_sym_BANG_EQ] = 482,
        [anon_sym_LT] = 482,
        [anon_sym_LT_EQ] = 482,
        [anon_sym_GT] = 482,
        [anon_sym_GT_EQ] = 482,
        [anon_sym_AMP_AMP] = 482,
        [anon_sym_PIPE_PIPE] = 482,
        [sym_comment] = 8,
    },
    [147] = {
        [anon_sym_LPAREN] = 484,
        [anon_sym_STAR] = 484,
        [anon_sym_RBRACK] = 484,
        [anon_sym_SLASH] = 484,
        [anon_sym_PERCENT] = 484,
        [anon_sym_LT_LT] = 484,
        [anon_sym_GT_GT] = 484,
        [anon_sym_AMP] = 484,
        [anon_sym_AMP_CARET] = 484,
        [anon_sym_PLUS] = 484,
        [anon_sym_DASH] = 484,
        [anon_sym_PIPE] = 484,
        [anon_sym_CARET] = 484,
        [anon_sym_EQ_EQ] = 484,
        [anon_sym_BANG_EQ] = 484,
        [anon_sym_LT] = 484,
        [anon_sym_LT_EQ] = 484,
        [anon_sym_GT] = 484,
        [anon_sym_GT_EQ] = 484,
        [anon_sym_AMP_AMP] = 484,
        [anon_sym_PIPE_PIPE] = 484,
        [sym_comment] = 8,
    },
    [148] = {
        [sym__type] = 486,
        [sym_pointer_type] = 356,
        [sym_array_type] = 356,
        [sym_slice_type] = 356,
        [sym_struct_type] = 356,
        [sym_interface_type] = 356,
        [sym_map_type] = 356,
        [sym_channel_type] = 356,
        [sym_function_type] = 356,
        [sym_qualified_identifier] = 356,
        [anon_sym_func] = 358,
        [anon_sym_STAR] = 360,
        [anon_sym_LBRACK] = 362,
        [anon_sym_struct] = 364,
        [anon_sym_interface] = 366,
        [anon_sym_map] = 368,
        [anon_sym_chan] = 370,
        [anon_sym_LT_DASH] = 372,
        [sym_identifier] = 374,
        [sym_comment] = 8,
    },
    [149] = {
        [anon_sym_LPAREN] = 400,
        [anon_sym_STAR] = 400,
        [anon_sym_RBRACK] = 400,
        [anon_sym_SLASH] = 400,
        [anon_sym_PERCENT] = 400,
        [anon_sym_LT_LT] = 400,
        [anon_sym_GT_GT] = 400,
        [anon_sym_AMP] = 400,
        [anon_sym_AMP_CARET] = 400,
        [anon_sym_PLUS] = 400,
        [anon_sym_DASH] = 400,
        [anon_sym_PIPE] = 400,
        [anon_sym_CARET] = 400,
        [anon_sym_EQ_EQ] = 400,
        [anon_sym_BANG_EQ] = 400,
        [anon_sym_LT] = 400,
        [anon_sym_LT_EQ] = 400,
        [anon_sym_GT] = 400,
        [anon_sym_GT_EQ] = 400,
        [anon_sym_AMP_AMP] = 400,
        [anon_sym_PIPE_PIPE] = 400,
        [sym_comment] = 8,
    },
    [150] = {
        [anon_sym_LPAREN] = 488,
        [anon_sym_STAR] = 488,
        [anon_sym_RBRACK] = 488,
        [anon_sym_SLASH] = 488,
        [anon_sym_PERCENT] = 488,
        [anon_sym_LT_LT] = 488,
        [anon_sym_GT_GT] = 488,
        [anon_sym_AMP] = 488,
        [anon_sym_AMP_CARET] = 488,
        [anon_sym_PLUS] = 488,
        [anon_sym_DASH] = 488,
        [anon_sym_PIPE] = 488,
        [anon_sym_CARET] = 488,
        [anon_sym_EQ_EQ] = 488,
        [anon_sym_BANG_EQ] = 488,
        [anon_sym_LT] = 488,
        [anon_sym_LT_EQ] = 488,
        [anon_sym_GT] = 488,
        [anon_sym_GT_EQ] = 488,
        [anon_sym_AMP_AMP] = 488,
        [anon_sym_PIPE_PIPE] = 488,
        [sym_comment] = 8,
    },
    [151] = {
        [sym__string_literal] = 490,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 490,
        [sym_raw_string_literal] = 490,
        [sym_interpreted_string_literal] = 490,
        [sym_comment] = 8,
    },
    [152] = {
        [sym_expression_list] = 492,
        [sym__expression] = 494,
        [sym_call_expression] = 496,
        [sym_unary_expression] = 496,
        [sym_binary_expression] = 496,
        [sym__primary_expression] = 496,
        [sym__string_literal] = 498,
        [sym_int_literal] = 498,
        [sym_float_literal] = 498,
        [sym_identifier] = 498,
        [sym_raw_string_literal] = 500,
        [sym_interpreted_string_literal] = 500,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 502,
        [sym_comment] = 8,
    },
    [153] = {
        [sym__expression] = 504,
        [sym_call_expression] = 132,
        [sym_unary_expression] = 132,
        [sym_binary_expression] = 132,
        [sym__primary_expression] = 132,
        [sym__string_literal] = 134,
        [sym_int_literal] = 134,
        [sym_float_literal] = 134,
        [sym_identifier] = 134,
        [sym_raw_string_literal] = 138,
        [sym_interpreted_string_literal] = 138,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 140,
        [sym_comment] = 8,
    },
    [154] = {
        [sym__type] = 506,
        [sym_pointer_type] = 356,
        [sym_array_type] = 356,
        [sym_slice_type] = 356,
        [sym_struct_type] = 356,
        [sym_interface_type] = 356,
        [sym_map_type] = 356,
        [sym_channel_type] = 356,
        [sym_function_type] = 356,
        [sym_qualified_identifier] = 356,
        [anon_sym_func] = 358,
        [anon_sym_STAR] = 360,
        [anon_sym_LBRACK] = 362,
        [anon_sym_struct] = 364,
        [anon_sym_interface] = 366,
        [anon_sym_map] = 368,
        [anon_sym_chan] = 370,
        [anon_sym_LT_DASH] = 372,
        [sym_identifier] = 374,
        [sym_comment] = 8,
    },
    [155] = {
        [sym__expression] = 508,
        [sym_call_expression] = 132,
        [sym_unary_expression] = 132,
        [sym_binary_expression] = 132,
        [sym__primary_expression] = 132,
        [sym__string_literal] = 134,
        [sym_int_literal] = 134,
        [sym_float_literal] = 134,
        [sym_identifier] = 134,
        [sym_raw_string_literal] = 138,
        [sym_interpreted_string_literal] = 138,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 140,
        [sym_comment] = 8,
    },
    [156] = {
        [sym__expression] = 510,
        [sym_call_expression] = 132,
        [sym_unary_expression] = 132,
        [sym_binary_expression] = 132,
        [sym__primary_expression] = 132,
        [sym__string_literal] = 134,
        [sym_int_literal] = 134,
        [sym_float_literal] = 134,
        [sym_identifier] = 134,
        [sym_raw_string_literal] = 138,
        [sym_interpreted_string_literal] = 138,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 140,
        [sym_comment] = 8,
    },
    [157] = {
        [sym__expression] = 512,
        [sym_call_expression] = 132,
        [sym_unary_expression] = 132,
        [sym_binary_expression] = 132,
        [sym__primary_expression] = 132,
        [sym__string_literal] = 134,
        [sym_int_literal] = 134,
        [sym_float_literal] = 134,
        [sym_identifier] = 134,
        [sym_raw_string_literal] = 138,
        [sym_interpreted_string_literal] = 138,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 140,
        [sym_comment] = 8,
    },
    [158] = {
        [sym__expression] = 514,
        [sym_call_expression] = 132,
        [sym_unary_expression] = 132,
        [sym_binary_expression] = 132,
        [sym__primary_expression] = 132,
        [sym__string_literal] = 134,
        [sym_int_literal] = 134,
        [sym_float_literal] = 134,
        [sym_identifier] = 134,
        [sym_raw_string_literal] = 138,
        [sym_interpreted_string_literal] = 138,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 140,
        [sym_comment] = 8,
    },
    [159] = {
        [anon_sym_LPAREN] = 516,
        [anon_sym_STAR] = 470,
        [anon_sym_RBRACK] = 516,
        [anon_sym_SLASH] = 470,
        [anon_sym_PERCENT] = 470,
        [anon_sym_LT_LT] = 470,
        [anon_sym_GT_GT] = 470,
        [anon_sym_AMP] = 470,
        [anon_sym_AMP_CARET] = 470,
        [anon_sym_PLUS] = 474,
        [anon_sym_DASH] = 474,
        [anon_sym_PIPE] = 474,
        [anon_sym_CARET] = 474,
        [anon_sym_EQ_EQ] = 476,
        [anon_sym_BANG_EQ] = 476,
        [anon_sym_LT] = 476,
        [anon_sym_LT_EQ] = 476,
        [anon_sym_GT] = 476,
        [anon_sym_GT_EQ] = 476,
        [anon_sym_AMP_AMP] = 478,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [160] = {
        [anon_sym_LPAREN] = 516,
        [anon_sym_STAR] = 470,
        [anon_sym_RBRACK] = 516,
        [anon_sym_SLASH] = 470,
        [anon_sym_PERCENT] = 470,
        [anon_sym_LT_LT] = 470,
        [anon_sym_GT_GT] = 470,
        [anon_sym_AMP] = 470,
        [anon_sym_AMP_CARET] = 470,
        [anon_sym_PLUS] = 474,
        [anon_sym_DASH] = 474,
        [anon_sym_PIPE] = 474,
        [anon_sym_CARET] = 474,
        [anon_sym_EQ_EQ] = 476,
        [anon_sym_BANG_EQ] = 476,
        [anon_sym_LT] = 476,
        [anon_sym_LT_EQ] = 476,
        [anon_sym_GT] = 476,
        [anon_sym_GT_EQ] = 476,
        [anon_sym_AMP_AMP] = 516,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [161] = {
        [anon_sym_LPAREN] = 516,
        [anon_sym_STAR] = 470,
        [anon_sym_RBRACK] = 516,
        [anon_sym_SLASH] = 470,
        [anon_sym_PERCENT] = 470,
        [anon_sym_LT_LT] = 470,
        [anon_sym_GT_GT] = 470,
        [anon_sym_AMP] = 470,
        [anon_sym_AMP_CARET] = 470,
        [anon_sym_PLUS] = 474,
        [anon_sym_DASH] = 474,
        [anon_sym_PIPE] = 474,
        [anon_sym_CARET] = 474,
        [anon_sym_EQ_EQ] = 516,
        [anon_sym_BANG_EQ] = 516,
        [anon_sym_LT] = 516,
        [anon_sym_LT_EQ] = 516,
        [anon_sym_GT] = 516,
        [anon_sym_GT_EQ] = 516,
        [anon_sym_AMP_AMP] = 516,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [162] = {
        [anon_sym_LPAREN] = 516,
        [anon_sym_STAR] = 470,
        [anon_sym_RBRACK] = 516,
        [anon_sym_SLASH] = 470,
        [anon_sym_PERCENT] = 470,
        [anon_sym_LT_LT] = 470,
        [anon_sym_GT_GT] = 470,
        [anon_sym_AMP] = 470,
        [anon_sym_AMP_CARET] = 470,
        [anon_sym_PLUS] = 516,
        [anon_sym_DASH] = 516,
        [anon_sym_PIPE] = 516,
        [anon_sym_CARET] = 516,
        [anon_sym_EQ_EQ] = 516,
        [anon_sym_BANG_EQ] = 516,
        [anon_sym_LT] = 516,
        [anon_sym_LT_EQ] = 516,
        [anon_sym_GT] = 516,
        [anon_sym_GT_EQ] = 516,
        [anon_sym_AMP_AMP] = 516,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [163] = {
        [anon_sym_LPAREN] = 518,
        [anon_sym_STAR] = 518,
        [anon_sym_RBRACK] = 518,
        [anon_sym_SLASH] = 518,
        [anon_sym_PERCENT] = 518,
        [anon_sym_LT_LT] = 518,
        [anon_sym_GT_GT] = 518,
        [anon_sym_AMP] = 518,
        [anon_sym_AMP_CARET] = 518,
        [anon_sym_PLUS] = 518,
        [anon_sym_DASH] = 518,
        [anon_sym_PIPE] = 518,
        [anon_sym_CARET] = 518,
        [anon_sym_EQ_EQ] = 518,
        [anon_sym_BANG_EQ] = 518,
        [anon_sym_LT] = 518,
        [anon_sym_LT_EQ] = 518,
        [anon_sym_GT] = 518,
        [anon_sym_GT_EQ] = 518,
        [anon_sym_AMP_AMP] = 518,
        [anon_sym_PIPE_PIPE] = 518,
        [sym_comment] = 8,
    },
    [164] = {
        [sym__string_literal] = 520,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 520,
        [sym_raw_string_literal] = 520,
        [sym_interpreted_string_literal] = 520,
        [sym_comment] = 8,
    },
    [165] = {
        [anon_sym_RPAREN] = 522,
        [sym_comment] = 8,
    },
    [166] = {
        [aux_sym_expression_list_repeat1] = 524,
        [anon_sym_LPAREN] = 526,
        [anon_sym_RPAREN] = 528,
        [anon_sym_COMMA] = 530,
        [anon_sym_STAR] = 532,
        [anon_sym_SLASH] = 532,
        [anon_sym_PERCENT] = 532,
        [anon_sym_LT_LT] = 532,
        [anon_sym_GT_GT] = 532,
        [anon_sym_AMP] = 532,
        [anon_sym_AMP_CARET] = 532,
        [anon_sym_PLUS] = 534,
        [anon_sym_DASH] = 534,
        [anon_sym_PIPE] = 534,
        [anon_sym_CARET] = 534,
        [anon_sym_EQ_EQ] = 536,
        [anon_sym_BANG_EQ] = 536,
        [anon_sym_LT] = 536,
        [anon_sym_LT_EQ] = 536,
        [anon_sym_GT] = 536,
        [anon_sym_GT_EQ] = 536,
        [anon_sym_AMP_AMP] = 538,
        [anon_sym_PIPE_PIPE] = 540,
        [sym_comment] = 8,
    },
    [167] = {
        [aux_sym_expression_list_repeat1] = 482,
        [anon_sym_LPAREN] = 482,
        [anon_sym_RPAREN] = 482,
        [anon_sym_COMMA] = 482,
        [anon_sym_STAR] = 482,
        [anon_sym_SLASH] = 482,
        [anon_sym_PERCENT] = 482,
        [anon_sym_LT_LT] = 482,
        [anon_sym_GT_GT] = 482,
        [anon_sym_AMP] = 482,
        [anon_sym_AMP_CARET] = 482,
        [anon_sym_PLUS] = 482,
        [anon_sym_DASH] = 482,
        [anon_sym_PIPE] = 482,
        [anon_sym_CARET] = 482,
        [anon_sym_EQ_EQ] = 482,
        [anon_sym_BANG_EQ] = 482,
        [anon_sym_LT] = 482,
        [anon_sym_LT_EQ] = 482,
        [anon_sym_GT] = 482,
        [anon_sym_GT_EQ] = 482,
        [anon_sym_AMP_AMP] = 482,
        [anon_sym_PIPE_PIPE] = 482,
        [sym_comment] = 8,
    },
    [168] = {
        [aux_sym_expression_list_repeat1] = 484,
        [anon_sym_LPAREN] = 484,
        [anon_sym_RPAREN] = 484,
        [anon_sym_COMMA] = 484,
        [anon_sym_STAR] = 484,
        [anon_sym_SLASH] = 484,
        [anon_sym_PERCENT] = 484,
        [anon_sym_LT_LT] = 484,
        [anon_sym_GT_GT] = 484,
        [anon_sym_AMP] = 484,
        [anon_sym_AMP_CARET] = 484,
        [anon_sym_PLUS] = 484,
        [anon_sym_DASH] = 484,
        [anon_sym_PIPE] = 484,
        [anon_sym_CARET] = 484,
        [anon_sym_EQ_EQ] = 484,
        [anon_sym_BANG_EQ] = 484,
        [anon_sym_LT] = 484,
        [anon_sym_LT_EQ] = 484,
        [anon_sym_GT] = 484,
        [anon_sym_GT_EQ] = 484,
        [anon_sym_AMP_AMP] = 484,
        [anon_sym_PIPE_PIPE] = 484,
        [sym_comment] = 8,
    },
    [169] = {
        [aux_sym_expression_list_repeat1] = 400,
        [anon_sym_LPAREN] = 400,
        [anon_sym_RPAREN] = 400,
        [anon_sym_COMMA] = 400,
        [anon_sym_STAR] = 400,
        [anon_sym_SLASH] = 400,
        [anon_sym_PERCENT] = 400,
        [anon_sym_LT_LT] = 400,
        [anon_sym_GT_GT] = 400,
        [anon_sym_AMP] = 400,
        [anon_sym_AMP_CARET] = 400,
        [anon_sym_PLUS] = 400,
        [anon_sym_DASH] = 400,
        [anon_sym_PIPE] = 400,
        [anon_sym_CARET] = 400,
        [anon_sym_EQ_EQ] = 400,
        [anon_sym_BANG_EQ] = 400,
        [anon_sym_LT] = 400,
        [anon_sym_LT_EQ] = 400,
        [anon_sym_GT] = 400,
        [anon_sym_GT_EQ] = 400,
        [anon_sym_AMP_AMP] = 400,
        [anon_sym_PIPE_PIPE] = 400,
        [sym_comment] = 8,
    },
    [170] = {
        [aux_sym_expression_list_repeat1] = 488,
        [anon_sym_LPAREN] = 488,
        [anon_sym_RPAREN] = 488,
        [anon_sym_COMMA] = 488,
        [anon_sym_STAR] = 488,
        [anon_sym_SLASH] = 488,
        [anon_sym_PERCENT] = 488,
        [anon_sym_LT_LT] = 488,
        [anon_sym_GT_GT] = 488,
        [anon_sym_AMP] = 488,
        [anon_sym_AMP_CARET] = 488,
        [anon_sym_PLUS] = 488,
        [anon_sym_DASH] = 488,
        [anon_sym_PIPE] = 488,
        [anon_sym_CARET] = 488,
        [anon_sym_EQ_EQ] = 488,
        [anon_sym_BANG_EQ] = 488,
        [anon_sym_LT] = 488,
        [anon_sym_LT_EQ] = 488,
        [anon_sym_GT] = 488,
        [anon_sym_GT_EQ] = 488,
        [anon_sym_AMP_AMP] = 488,
        [anon_sym_PIPE_PIPE] = 488,
        [sym_comment] = 8,
    },
    [171] = {
        [anon_sym_RPAREN] = 542,
        [sym_comment] = 8,
    },
    [172] = {
        [sym_expression_list] = 544,
        [sym__expression] = 494,
        [sym_call_expression] = 496,
        [sym_unary_expression] = 496,
        [sym_binary_expression] = 496,
        [sym__primary_expression] = 496,
        [sym__string_literal] = 498,
        [sym_int_literal] = 498,
        [sym_float_literal] = 498,
        [sym_identifier] = 498,
        [sym_raw_string_literal] = 500,
        [sym_interpreted_string_literal] = 500,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 502,
        [sym_comment] = 8,
    },
    [173] = {
        [sym__expression] = 546,
        [sym_call_expression] = 496,
        [sym_unary_expression] = 496,
        [sym_binary_expression] = 496,
        [sym__primary_expression] = 496,
        [sym__string_literal] = 498,
        [sym_int_literal] = 498,
        [sym_float_literal] = 498,
        [sym_identifier] = 498,
        [sym_raw_string_literal] = 500,
        [sym_interpreted_string_literal] = 500,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 502,
        [sym_comment] = 8,
    },
    [174] = {
        [sym__expression] = 548,
        [sym_call_expression] = 496,
        [sym_unary_expression] = 496,
        [sym_binary_expression] = 496,
        [sym__primary_expression] = 496,
        [sym__string_literal] = 498,
        [sym_int_literal] = 498,
        [sym_float_literal] = 498,
        [sym_identifier] = 498,
        [sym_raw_string_literal] = 500,
        [sym_interpreted_string_literal] = 500,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 502,
        [sym_comment] = 8,
    },
    [175] = {
        [sym__expression] = 550,
        [sym_call_expression] = 496,
        [sym_unary_expression] = 496,
        [sym_binary_expression] = 496,
        [sym__primary_expression] = 496,
        [sym__string_literal] = 498,
        [sym_int_literal] = 498,
        [sym_float_literal] = 498,
        [sym_identifier] = 498,
        [sym_raw_string_literal] = 500,
        [sym_interpreted_string_literal] = 500,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 502,
        [sym_comment] = 8,
    },
    [176] = {
        [sym__expression] = 552,
        [sym_call_expression] = 496,
        [sym_unary_expression] = 496,
        [sym_binary_expression] = 496,
        [sym__primary_expression] = 496,
        [sym__string_literal] = 498,
        [sym_int_literal] = 498,
        [sym_float_literal] = 498,
        [sym_identifier] = 498,
        [sym_raw_string_literal] = 500,
        [sym_interpreted_string_literal] = 500,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 502,
        [sym_comment] = 8,
    },
    [177] = {
        [sym__expression] = 554,
        [sym_call_expression] = 496,
        [sym_unary_expression] = 496,
        [sym_binary_expression] = 496,
        [sym__primary_expression] = 496,
        [sym__string_literal] = 498,
        [sym_int_literal] = 498,
        [sym_float_literal] = 498,
        [sym_identifier] = 498,
        [sym_raw_string_literal] = 500,
        [sym_interpreted_string_literal] = 500,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 502,
        [sym_comment] = 8,
    },
    [178] = {
        [sym__expression] = 556,
        [sym_call_expression] = 496,
        [sym_unary_expression] = 496,
        [sym_binary_expression] = 496,
        [sym__primary_expression] = 496,
        [sym__string_literal] = 498,
        [sym_int_literal] = 498,
        [sym_float_literal] = 498,
        [sym_identifier] = 498,
        [sym_raw_string_literal] = 500,
        [sym_interpreted_string_literal] = 500,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 502,
        [sym_comment] = 8,
    },
    [179] = {
        [aux_sym_expression_list_repeat1] = 516,
        [anon_sym_LPAREN] = 516,
        [anon_sym_RPAREN] = 516,
        [anon_sym_COMMA] = 516,
        [anon_sym_STAR] = 532,
        [anon_sym_SLASH] = 532,
        [anon_sym_PERCENT] = 532,
        [anon_sym_LT_LT] = 532,
        [anon_sym_GT_GT] = 532,
        [anon_sym_AMP] = 532,
        [anon_sym_AMP_CARET] = 532,
        [anon_sym_PLUS] = 534,
        [anon_sym_DASH] = 534,
        [anon_sym_PIPE] = 534,
        [anon_sym_CARET] = 534,
        [anon_sym_EQ_EQ] = 536,
        [anon_sym_BANG_EQ] = 536,
        [anon_sym_LT] = 536,
        [anon_sym_LT_EQ] = 536,
        [anon_sym_GT] = 536,
        [anon_sym_GT_EQ] = 536,
        [anon_sym_AMP_AMP] = 538,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [180] = {
        [aux_sym_expression_list_repeat1] = 516,
        [anon_sym_LPAREN] = 516,
        [anon_sym_RPAREN] = 516,
        [anon_sym_COMMA] = 516,
        [anon_sym_STAR] = 532,
        [anon_sym_SLASH] = 532,
        [anon_sym_PERCENT] = 532,
        [anon_sym_LT_LT] = 532,
        [anon_sym_GT_GT] = 532,
        [anon_sym_AMP] = 532,
        [anon_sym_AMP_CARET] = 532,
        [anon_sym_PLUS] = 534,
        [anon_sym_DASH] = 534,
        [anon_sym_PIPE] = 534,
        [anon_sym_CARET] = 534,
        [anon_sym_EQ_EQ] = 536,
        [anon_sym_BANG_EQ] = 536,
        [anon_sym_LT] = 536,
        [anon_sym_LT_EQ] = 536,
        [anon_sym_GT] = 536,
        [anon_sym_GT_EQ] = 536,
        [anon_sym_AMP_AMP] = 516,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [181] = {
        [aux_sym_expression_list_repeat1] = 516,
        [anon_sym_LPAREN] = 516,
        [anon_sym_RPAREN] = 516,
        [anon_sym_COMMA] = 516,
        [anon_sym_STAR] = 532,
        [anon_sym_SLASH] = 532,
        [anon_sym_PERCENT] = 532,
        [anon_sym_LT_LT] = 532,
        [anon_sym_GT_GT] = 532,
        [anon_sym_AMP] = 532,
        [anon_sym_AMP_CARET] = 532,
        [anon_sym_PLUS] = 534,
        [anon_sym_DASH] = 534,
        [anon_sym_PIPE] = 534,
        [anon_sym_CARET] = 534,
        [anon_sym_EQ_EQ] = 516,
        [anon_sym_BANG_EQ] = 516,
        [anon_sym_LT] = 516,
        [anon_sym_LT_EQ] = 516,
        [anon_sym_GT] = 516,
        [anon_sym_GT_EQ] = 516,
        [anon_sym_AMP_AMP] = 516,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [182] = {
        [aux_sym_expression_list_repeat1] = 516,
        [anon_sym_LPAREN] = 516,
        [anon_sym_RPAREN] = 516,
        [anon_sym_COMMA] = 516,
        [anon_sym_STAR] = 532,
        [anon_sym_SLASH] = 532,
        [anon_sym_PERCENT] = 532,
        [anon_sym_LT_LT] = 532,
        [anon_sym_GT_GT] = 532,
        [anon_sym_AMP] = 532,
        [anon_sym_AMP_CARET] = 532,
        [anon_sym_PLUS] = 516,
        [anon_sym_DASH] = 516,
        [anon_sym_PIPE] = 516,
        [anon_sym_CARET] = 516,
        [anon_sym_EQ_EQ] = 516,
        [anon_sym_BANG_EQ] = 516,
        [anon_sym_LT] = 516,
        [anon_sym_LT_EQ] = 516,
        [anon_sym_GT] = 516,
        [anon_sym_GT_EQ] = 516,
        [anon_sym_AMP_AMP] = 516,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [183] = {
        [aux_sym_expression_list_repeat1] = 518,
        [anon_sym_LPAREN] = 518,
        [anon_sym_RPAREN] = 518,
        [anon_sym_COMMA] = 518,
        [anon_sym_STAR] = 518,
        [anon_sym_SLASH] = 518,
        [anon_sym_PERCENT] = 518,
        [anon_sym_LT_LT] = 518,
        [anon_sym_GT_GT] = 518,
        [anon_sym_AMP] = 518,
        [anon_sym_AMP_CARET] = 518,
        [anon_sym_PLUS] = 518,
        [anon_sym_DASH] = 518,
        [anon_sym_PIPE] = 518,
        [anon_sym_CARET] = 518,
        [anon_sym_EQ_EQ] = 518,
        [anon_sym_BANG_EQ] = 518,
        [anon_sym_LT] = 518,
        [anon_sym_LT_EQ] = 518,
        [anon_sym_GT] = 518,
        [anon_sym_GT_EQ] = 518,
        [anon_sym_AMP_AMP] = 518,
        [anon_sym_PIPE_PIPE] = 518,
        [sym_comment] = 8,
    },
    [184] = {
        [aux_sym_expression_list_repeat1] = 558,
        [anon_sym_LPAREN] = 526,
        [anon_sym_RPAREN] = 560,
        [anon_sym_COMMA] = 530,
        [anon_sym_STAR] = 532,
        [anon_sym_SLASH] = 532,
        [anon_sym_PERCENT] = 532,
        [anon_sym_LT_LT] = 532,
        [anon_sym_GT_GT] = 532,
        [anon_sym_AMP] = 532,
        [anon_sym_AMP_CARET] = 532,
        [anon_sym_PLUS] = 534,
        [anon_sym_DASH] = 534,
        [anon_sym_PIPE] = 534,
        [anon_sym_CARET] = 534,
        [anon_sym_EQ_EQ] = 536,
        [anon_sym_BANG_EQ] = 536,
        [anon_sym_LT] = 536,
        [anon_sym_LT_EQ] = 536,
        [anon_sym_GT] = 536,
        [anon_sym_GT_EQ] = 536,
        [anon_sym_AMP_AMP] = 538,
        [anon_sym_PIPE_PIPE] = 540,
        [sym_comment] = 8,
    },
    [185] = {
        [anon_sym_RPAREN] = 562,
        [sym_comment] = 8,
    },
    [186] = {
        [anon_sym_RPAREN] = 564,
        [sym_comment] = 8,
    },
    [187] = {
        [aux_sym_expression_list_repeat1] = 566,
        [anon_sym_LPAREN] = 566,
        [anon_sym_RPAREN] = 566,
        [anon_sym_COMMA] = 566,
        [anon_sym_STAR] = 566,
        [anon_sym_SLASH] = 566,
        [anon_sym_PERCENT] = 566,
        [anon_sym_LT_LT] = 566,
        [anon_sym_GT_GT] = 566,
        [anon_sym_AMP] = 566,
        [anon_sym_AMP_CARET] = 566,
        [anon_sym_PLUS] = 566,
        [anon_sym_DASH] = 566,
        [anon_sym_PIPE] = 566,
        [anon_sym_CARET] = 566,
        [anon_sym_EQ_EQ] = 566,
        [anon_sym_BANG_EQ] = 566,
        [anon_sym_LT] = 566,
        [anon_sym_LT_EQ] = 566,
        [anon_sym_GT] = 566,
        [anon_sym_GT_EQ] = 566,
        [anon_sym_AMP_AMP] = 566,
        [anon_sym_PIPE_PIPE] = 566,
        [sym_comment] = 8,
    },
    [188] = {
        [anon_sym_LPAREN] = 566,
        [anon_sym_STAR] = 566,
        [anon_sym_RBRACK] = 566,
        [anon_sym_SLASH] = 566,
        [anon_sym_PERCENT] = 566,
        [anon_sym_LT_LT] = 566,
        [anon_sym_GT_GT] = 566,
        [anon_sym_AMP] = 566,
        [anon_sym_AMP_CARET] = 566,
        [anon_sym_PLUS] = 566,
        [anon_sym_DASH] = 566,
        [anon_sym_PIPE] = 566,
        [anon_sym_CARET] = 566,
        [anon_sym_EQ_EQ] = 566,
        [anon_sym_BANG_EQ] = 566,
        [anon_sym_LT] = 566,
        [anon_sym_LT_EQ] = 566,
        [anon_sym_GT] = 566,
        [anon_sym_GT_EQ] = 566,
        [anon_sym_AMP_AMP] = 566,
        [anon_sym_PIPE_PIPE] = 566,
        [sym_comment] = 8,
    },
    [189] = {
        [sym__string_literal] = 568,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 568,
        [sym_raw_string_literal] = 568,
        [sym_interpreted_string_literal] = 568,
        [sym_comment] = 8,
    },
    [190] = {
        [sym_parameters] = 570,
        [sym__type] = 570,
        [sym_pointer_type] = 356,
        [sym_array_type] = 356,
        [sym_slice_type] = 356,
        [sym_struct_type] = 356,
        [sym_interface_type] = 356,
        [sym_map_type] = 356,
        [sym_channel_type] = 356,
        [sym_function_type] = 356,
        [sym_qualified_identifier] = 356,
        [sym__string_literal] = 572,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 572,
        [anon_sym_LPAREN] = 574,
        [anon_sym_func] = 358,
        [anon_sym_STAR] = 360,
        [anon_sym_LBRACK] = 362,
        [anon_sym_struct] = 364,
        [anon_sym_interface] = 366,
        [anon_sym_map] = 368,
        [anon_sym_chan] = 370,
        [anon_sym_LT_DASH] = 372,
        [sym_identifier] = 374,
        [sym_raw_string_literal] = 572,
        [sym_interpreted_string_literal] = 572,
        [sym_comment] = 8,
    },
    [191] = {
        [sym__parameter_list] = 576,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 578,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [192] = {
        [anon_sym_RPAREN] = 580,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [193] = {
        [sym_parameters] = 272,
        [sym__type] = 272,
        [sym_pointer_type] = 272,
        [sym_array_type] = 272,
        [sym_slice_type] = 272,
        [sym_struct_type] = 272,
        [sym_interface_type] = 272,
        [sym_map_type] = 272,
        [sym_channel_type] = 272,
        [sym_function_type] = 272,
        [sym_qualified_identifier] = 272,
        [sym__string_literal] = 272,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 272,
        [anon_sym_LPAREN] = 272,
        [anon_sym_func] = 272,
        [anon_sym_STAR] = 272,
        [anon_sym_LBRACK] = 272,
        [anon_sym_struct] = 272,
        [anon_sym_interface] = 272,
        [anon_sym_map] = 272,
        [anon_sym_chan] = 272,
        [anon_sym_LT_DASH] = 272,
        [sym_identifier] = 272,
        [sym_raw_string_literal] = 272,
        [sym_interpreted_string_literal] = 272,
        [sym_comment] = 8,
    },
    [194] = {
        [sym_parameters] = 582,
        [sym__type] = 582,
        [sym_pointer_type] = 582,
        [sym_array_type] = 582,
        [sym_slice_type] = 582,
        [sym_struct_type] = 582,
        [sym_interface_type] = 582,
        [sym_map_type] = 582,
        [sym_channel_type] = 582,
        [sym_function_type] = 582,
        [sym_qualified_identifier] = 582,
        [sym__string_literal] = 582,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 582,
        [anon_sym_LPAREN] = 582,
        [anon_sym_func] = 582,
        [anon_sym_STAR] = 582,
        [anon_sym_LBRACK] = 582,
        [anon_sym_struct] = 582,
        [anon_sym_interface] = 582,
        [anon_sym_map] = 582,
        [anon_sym_chan] = 582,
        [anon_sym_LT_DASH] = 582,
        [sym_identifier] = 582,
        [sym_raw_string_literal] = 582,
        [sym_interpreted_string_literal] = 582,
        [sym_comment] = 8,
    },
    [195] = {
        [sym_parameter_declaration] = 584,
        [sym_identifier] = 586,
        [sym_comment] = 8,
    },
    [196] = {
        [anon_sym_RPAREN] = 588,
        [anon_sym_COMMA] = 588,
        [sym_comment] = 8,
    },
    [197] = {
        [sym__type] = 274,
        [sym_pointer_type] = 276,
        [sym_array_type] = 276,
        [sym_slice_type] = 276,
        [sym_struct_type] = 276,
        [sym_interface_type] = 276,
        [sym_map_type] = 276,
        [sym_channel_type] = 276,
        [sym_function_type] = 276,
        [sym_qualified_identifier] = 276,
        [anon_sym_RPAREN] = 588,
        [anon_sym_func] = 278,
        [anon_sym_COMMA] = 588,
        [anon_sym_STAR] = 280,
        [anon_sym_LBRACK] = 282,
        [anon_sym_struct] = 284,
        [anon_sym_interface] = 286,
        [anon_sym_map] = 288,
        [anon_sym_chan] = 290,
        [anon_sym_LT_DASH] = 292,
        [sym_identifier] = 294,
        [sym_comment] = 8,
    },
    [198] = {
        [sym__string_literal] = 590,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 590,
        [sym_raw_string_literal] = 590,
        [sym_interpreted_string_literal] = 590,
        [sym_comment] = 8,
    },
    [199] = {
        [sym__parameter_list] = 592,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 594,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [200] = {
        [anon_sym_RPAREN] = 596,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [201] = {
        [sym__string_literal] = 272,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 272,
        [sym_raw_string_literal] = 272,
        [sym_interpreted_string_literal] = 272,
        [sym_comment] = 8,
    },
    [202] = {
        [sym__string_literal] = 582,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 582,
        [sym_raw_string_literal] = 582,
        [sym_interpreted_string_literal] = 582,
        [sym_comment] = 8,
    },
    [203] = {
        [anon_sym_LPAREN] = 468,
        [anon_sym_STAR] = 470,
        [anon_sym_RBRACK] = 598,
        [anon_sym_SLASH] = 470,
        [anon_sym_PERCENT] = 470,
        [anon_sym_LT_LT] = 470,
        [anon_sym_GT_GT] = 470,
        [anon_sym_AMP] = 470,
        [anon_sym_AMP_CARET] = 470,
        [anon_sym_PLUS] = 474,
        [anon_sym_DASH] = 474,
        [anon_sym_PIPE] = 474,
        [anon_sym_CARET] = 474,
        [anon_sym_EQ_EQ] = 476,
        [anon_sym_BANG_EQ] = 476,
        [anon_sym_LT] = 476,
        [anon_sym_LT_EQ] = 476,
        [anon_sym_GT] = 476,
        [anon_sym_GT_EQ] = 476,
        [anon_sym_AMP_AMP] = 478,
        [anon_sym_PIPE_PIPE] = 480,
        [sym_comment] = 8,
    },
    [204] = {
        [sym__type] = 600,
        [sym_pointer_type] = 276,
        [sym_array_type] = 276,
        [sym_slice_type] = 276,
        [sym_struct_type] = 276,
        [sym_interface_type] = 276,
        [sym_map_type] = 276,
        [sym_channel_type] = 276,
        [sym_function_type] = 276,
        [sym_qualified_identifier] = 276,
        [anon_sym_func] = 278,
        [anon_sym_STAR] = 280,
        [anon_sym_LBRACK] = 282,
        [anon_sym_struct] = 284,
        [anon_sym_interface] = 286,
        [anon_sym_map] = 288,
        [anon_sym_chan] = 290,
        [anon_sym_LT_DASH] = 292,
        [sym_identifier] = 294,
        [sym_comment] = 8,
    },
    [205] = {
        [anon_sym_RPAREN] = 490,
        [anon_sym_COMMA] = 490,
        [sym_comment] = 8,
    },
    [206] = {
        [sym__type] = 602,
        [sym_pointer_type] = 276,
        [sym_array_type] = 276,
        [sym_slice_type] = 276,
        [sym_struct_type] = 276,
        [sym_interface_type] = 276,
        [sym_map_type] = 276,
        [sym_channel_type] = 276,
        [sym_function_type] = 276,
        [sym_qualified_identifier] = 276,
        [anon_sym_func] = 278,
        [anon_sym_STAR] = 280,
        [anon_sym_LBRACK] = 282,
        [anon_sym_struct] = 284,
        [anon_sym_interface] = 286,
        [anon_sym_map] = 288,
        [anon_sym_chan] = 290,
        [anon_sym_LT_DASH] = 292,
        [sym_identifier] = 294,
        [sym_comment] = 8,
    },
    [207] = {
        [anon_sym_RPAREN] = 520,
        [anon_sym_COMMA] = 520,
        [sym_comment] = 8,
    },
    [208] = {
        [anon_sym_RPAREN] = 568,
        [anon_sym_COMMA] = 568,
        [sym_comment] = 8,
    },
    [209] = {
        [sym_parameters] = 604,
        [sym__type] = 604,
        [sym_pointer_type] = 276,
        [sym_array_type] = 276,
        [sym_slice_type] = 276,
        [sym_struct_type] = 276,
        [sym_interface_type] = 276,
        [sym_map_type] = 276,
        [sym_channel_type] = 276,
        [sym_function_type] = 276,
        [sym_qualified_identifier] = 276,
        [anon_sym_LPAREN] = 606,
        [anon_sym_RPAREN] = 572,
        [anon_sym_func] = 278,
        [anon_sym_COMMA] = 572,
        [anon_sym_STAR] = 280,
        [anon_sym_LBRACK] = 282,
        [anon_sym_struct] = 284,
        [anon_sym_interface] = 286,
        [anon_sym_map] = 288,
        [anon_sym_chan] = 290,
        [anon_sym_LT_DASH] = 292,
        [sym_identifier] = 294,
        [sym_comment] = 8,
    },
    [210] = {
        [sym__parameter_list] = 608,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 610,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [211] = {
        [anon_sym_RPAREN] = 612,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [212] = {
        [sym_parameters] = 272,
        [sym__type] = 272,
        [sym_pointer_type] = 272,
        [sym_array_type] = 272,
        [sym_slice_type] = 272,
        [sym_struct_type] = 272,
        [sym_interface_type] = 272,
        [sym_map_type] = 272,
        [sym_channel_type] = 272,
        [sym_function_type] = 272,
        [sym_qualified_identifier] = 272,
        [anon_sym_LPAREN] = 272,
        [anon_sym_RPAREN] = 272,
        [anon_sym_func] = 272,
        [anon_sym_COMMA] = 272,
        [anon_sym_STAR] = 272,
        [anon_sym_LBRACK] = 272,
        [anon_sym_struct] = 272,
        [anon_sym_interface] = 272,
        [anon_sym_map] = 272,
        [anon_sym_chan] = 272,
        [anon_sym_LT_DASH] = 272,
        [sym_identifier] = 272,
        [sym_comment] = 8,
    },
    [213] = {
        [sym_parameters] = 582,
        [sym__type] = 582,
        [sym_pointer_type] = 582,
        [sym_array_type] = 582,
        [sym_slice_type] = 582,
        [sym_struct_type] = 582,
        [sym_interface_type] = 582,
        [sym_map_type] = 582,
        [sym_channel_type] = 582,
        [sym_function_type] = 582,
        [sym_qualified_identifier] = 582,
        [anon_sym_LPAREN] = 582,
        [anon_sym_RPAREN] = 582,
        [anon_sym_func] = 582,
        [anon_sym_COMMA] = 582,
        [anon_sym_STAR] = 582,
        [anon_sym_LBRACK] = 582,
        [anon_sym_struct] = 582,
        [anon_sym_interface] = 582,
        [anon_sym_map] = 582,
        [anon_sym_chan] = 582,
        [anon_sym_LT_DASH] = 582,
        [sym_identifier] = 582,
        [sym_comment] = 8,
    },
    [214] = {
        [anon_sym_RPAREN] = 590,
        [anon_sym_COMMA] = 590,
        [sym_comment] = 8,
    },
    [215] = {
        [sym__parameter_list] = 614,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 616,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [216] = {
        [anon_sym_RPAREN] = 618,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [217] = {
        [anon_sym_RPAREN] = 272,
        [anon_sym_COMMA] = 272,
        [sym_comment] = 8,
    },
    [218] = {
        [anon_sym_RPAREN] = 582,
        [anon_sym_COMMA] = 582,
        [sym_comment] = 8,
    },
    [219] = {
        [sym_parameters] = 582,
        [sym__type] = 582,
        [sym_pointer_type] = 582,
        [sym_array_type] = 582,
        [sym_slice_type] = 582,
        [sym_struct_type] = 582,
        [sym_interface_type] = 582,
        [sym_map_type] = 582,
        [sym_channel_type] = 582,
        [sym_function_type] = 582,
        [sym_qualified_identifier] = 582,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 582,
        [anon_sym_LPAREN] = 582,
        [anon_sym_func] = 582,
        [anon_sym_STAR] = 582,
        [anon_sym_LBRACK] = 582,
        [anon_sym_struct] = 582,
        [anon_sym_interface] = 582,
        [anon_sym_map] = 582,
        [anon_sym_chan] = 582,
        [anon_sym_LT_DASH] = 582,
        [sym_identifier] = 582,
        [sym_comment] = 8,
    },
    [220] = {
        [anon_sym_RBRACE] = 620,
        [sym_comment] = 8,
    },
    [221] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 622,
        [sym_comment] = 8,
    },
    [222] = {
        [sym__parameter_list] = 624,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 626,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [223] = {
        [anon_sym_RPAREN] = 628,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [224] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 272,
        [sym_comment] = 8,
    },
    [225] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 582,
        [sym_comment] = 8,
    },
    [226] = {
        [anon_sym_RBRACK] = 340,
        [sym_comment] = 8,
    },
    [227] = {
        [sym_identifier_list] = 342,
        [sym_field_declaration] = 344,
        [aux_sym_struct_type_repeat1] = 630,
        [anon_sym_STAR] = 348,
        [anon_sym_RBRACE] = 632,
        [sym_identifier] = 352,
        [sym_comment] = 8,
    },
    [228] = {
        [anon_sym_RBRACE] = 634,
        [sym_comment] = 8,
    },
    [229] = {
        [anon_sym_RBRACK] = 380,
        [sym_comment] = 8,
    },
    [230] = {
        [anon_sym_RBRACK] = 412,
        [sym_comment] = 8,
    },
    [231] = {
        [anon_sym_LPAREN] = 468,
        [anon_sym_STAR] = 470,
        [anon_sym_RBRACK] = 636,
        [anon_sym_SLASH] = 470,
        [anon_sym_PERCENT] = 470,
        [anon_sym_LT_LT] = 470,
        [anon_sym_GT_GT] = 470,
        [anon_sym_AMP] = 470,
        [anon_sym_AMP_CARET] = 470,
        [anon_sym_PLUS] = 474,
        [anon_sym_DASH] = 474,
        [anon_sym_PIPE] = 474,
        [anon_sym_CARET] = 474,
        [anon_sym_EQ_EQ] = 476,
        [anon_sym_BANG_EQ] = 476,
        [anon_sym_LT] = 476,
        [anon_sym_LT_EQ] = 476,
        [anon_sym_GT] = 476,
        [anon_sym_GT_EQ] = 476,
        [anon_sym_AMP_AMP] = 478,
        [anon_sym_PIPE_PIPE] = 480,
        [sym_comment] = 8,
    },
    [232] = {
        [sym__type] = 638,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [233] = {
        [anon_sym_RBRACK] = 490,
        [sym_comment] = 8,
    },
    [234] = {
        [sym__type] = 640,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [235] = {
        [anon_sym_RBRACK] = 520,
        [sym_comment] = 8,
    },
    [236] = {
        [anon_sym_RBRACK] = 568,
        [sym_comment] = 8,
    },
    [237] = {
        [sym_parameters] = 642,
        [sym__type] = 642,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_LPAREN] = 644,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_RBRACK] = 572,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [238] = {
        [sym__parameter_list] = 646,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 648,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [239] = {
        [anon_sym_RPAREN] = 650,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [240] = {
        [sym_parameters] = 272,
        [sym__type] = 272,
        [sym_pointer_type] = 272,
        [sym_array_type] = 272,
        [sym_slice_type] = 272,
        [sym_struct_type] = 272,
        [sym_interface_type] = 272,
        [sym_map_type] = 272,
        [sym_channel_type] = 272,
        [sym_function_type] = 272,
        [sym_qualified_identifier] = 272,
        [anon_sym_LPAREN] = 272,
        [anon_sym_func] = 272,
        [anon_sym_STAR] = 272,
        [anon_sym_LBRACK] = 272,
        [anon_sym_RBRACK] = 272,
        [anon_sym_struct] = 272,
        [anon_sym_interface] = 272,
        [anon_sym_map] = 272,
        [anon_sym_chan] = 272,
        [anon_sym_LT_DASH] = 272,
        [sym_identifier] = 272,
        [sym_comment] = 8,
    },
    [241] = {
        [sym_parameters] = 582,
        [sym__type] = 582,
        [sym_pointer_type] = 582,
        [sym_array_type] = 582,
        [sym_slice_type] = 582,
        [sym_struct_type] = 582,
        [sym_interface_type] = 582,
        [sym_map_type] = 582,
        [sym_channel_type] = 582,
        [sym_function_type] = 582,
        [sym_qualified_identifier] = 582,
        [anon_sym_LPAREN] = 582,
        [anon_sym_func] = 582,
        [anon_sym_STAR] = 582,
        [anon_sym_LBRACK] = 582,
        [anon_sym_RBRACK] = 582,
        [anon_sym_struct] = 582,
        [anon_sym_interface] = 582,
        [anon_sym_map] = 582,
        [anon_sym_chan] = 582,
        [anon_sym_LT_DASH] = 582,
        [sym_identifier] = 582,
        [sym_comment] = 8,
    },
    [242] = {
        [anon_sym_RBRACK] = 590,
        [sym_comment] = 8,
    },
    [243] = {
        [sym__parameter_list] = 652,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 654,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [244] = {
        [anon_sym_RPAREN] = 656,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [245] = {
        [anon_sym_RBRACK] = 272,
        [sym_comment] = 8,
    },
    [246] = {
        [anon_sym_RBRACK] = 582,
        [sym_comment] = 8,
    },
    [247] = {
        [sym__type] = 658,
        [sym_pointer_type] = 100,
        [sym_array_type] = 100,
        [sym_slice_type] = 100,
        [sym_struct_type] = 100,
        [sym_interface_type] = 100,
        [sym_map_type] = 100,
        [sym_channel_type] = 100,
        [sym_function_type] = 100,
        [sym_qualified_identifier] = 100,
        [anon_sym_func] = 102,
        [anon_sym_STAR] = 104,
        [anon_sym_LBRACK] = 106,
        [anon_sym_struct] = 108,
        [anon_sym_interface] = 110,
        [anon_sym_map] = 112,
        [anon_sym_chan] = 114,
        [anon_sym_LT_DASH] = 116,
        [sym_identifier] = 118,
        [sym_comment] = 8,
    },
    [248] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 230,
        [sym_comment] = 8,
    },
    [249] = {
        [sym_method_spec] = 232,
        [aux_sym_interface_type_repeat1] = 660,
        [anon_sym_RBRACE] = 662,
        [sym_identifier] = 238,
        [sym_comment] = 8,
    },
    [250] = {
        [anon_sym_RBRACE] = 664,
        [sym_comment] = 8,
    },
    [251] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 244,
        [sym_comment] = 8,
    },
    [252] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 340,
        [sym_comment] = 8,
    },
    [253] = {
        [sym_identifier_list] = 342,
        [sym_field_declaration] = 344,
        [aux_sym_struct_type_repeat1] = 666,
        [anon_sym_STAR] = 348,
        [anon_sym_RBRACE] = 668,
        [sym_identifier] = 352,
        [sym_comment] = 8,
    },
    [254] = {
        [anon_sym_RBRACE] = 670,
        [sym_comment] = 8,
    },
    [255] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 380,
        [sym_comment] = 8,
    },
    [256] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 412,
        [sym_comment] = 8,
    },
    [257] = {
        [anon_sym_LPAREN] = 468,
        [anon_sym_STAR] = 470,
        [anon_sym_RBRACK] = 672,
        [anon_sym_SLASH] = 470,
        [anon_sym_PERCENT] = 470,
        [anon_sym_LT_LT] = 470,
        [anon_sym_GT_GT] = 470,
        [anon_sym_AMP] = 470,
        [anon_sym_AMP_CARET] = 470,
        [anon_sym_PLUS] = 474,
        [anon_sym_DASH] = 474,
        [anon_sym_PIPE] = 474,
        [anon_sym_CARET] = 474,
        [anon_sym_EQ_EQ] = 476,
        [anon_sym_BANG_EQ] = 476,
        [anon_sym_LT] = 476,
        [anon_sym_LT_EQ] = 476,
        [anon_sym_GT] = 476,
        [anon_sym_GT_EQ] = 476,
        [anon_sym_AMP_AMP] = 478,
        [anon_sym_PIPE_PIPE] = 480,
        [sym_comment] = 8,
    },
    [258] = {
        [sym__type] = 674,
        [sym_pointer_type] = 100,
        [sym_array_type] = 100,
        [sym_slice_type] = 100,
        [sym_struct_type] = 100,
        [sym_interface_type] = 100,
        [sym_map_type] = 100,
        [sym_channel_type] = 100,
        [sym_function_type] = 100,
        [sym_qualified_identifier] = 100,
        [anon_sym_func] = 102,
        [anon_sym_STAR] = 104,
        [anon_sym_LBRACK] = 106,
        [anon_sym_struct] = 108,
        [anon_sym_interface] = 110,
        [anon_sym_map] = 112,
        [anon_sym_chan] = 114,
        [anon_sym_LT_DASH] = 116,
        [sym_identifier] = 118,
        [sym_comment] = 8,
    },
    [259] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 490,
        [sym_comment] = 8,
    },
    [260] = {
        [sym__type] = 676,
        [sym_pointer_type] = 100,
        [sym_array_type] = 100,
        [sym_slice_type] = 100,
        [sym_struct_type] = 100,
        [sym_interface_type] = 100,
        [sym_map_type] = 100,
        [sym_channel_type] = 100,
        [sym_function_type] = 100,
        [sym_qualified_identifier] = 100,
        [anon_sym_func] = 102,
        [anon_sym_STAR] = 104,
        [anon_sym_LBRACK] = 106,
        [anon_sym_struct] = 108,
        [anon_sym_interface] = 110,
        [anon_sym_map] = 112,
        [anon_sym_chan] = 114,
        [anon_sym_LT_DASH] = 116,
        [sym_identifier] = 118,
        [sym_comment] = 8,
    },
    [261] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 520,
        [sym_comment] = 8,
    },
    [262] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 568,
        [sym_comment] = 8,
    },
    [263] = {
        [sym_parameters] = 678,
        [sym__type] = 678,
        [sym_pointer_type] = 100,
        [sym_array_type] = 100,
        [sym_slice_type] = 100,
        [sym_struct_type] = 100,
        [sym_interface_type] = 100,
        [sym_map_type] = 100,
        [sym_channel_type] = 100,
        [sym_function_type] = 100,
        [sym_qualified_identifier] = 100,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 572,
        [anon_sym_LPAREN] = 252,
        [anon_sym_func] = 102,
        [anon_sym_STAR] = 104,
        [anon_sym_LBRACK] = 106,
        [anon_sym_struct] = 108,
        [anon_sym_interface] = 110,
        [anon_sym_map] = 112,
        [anon_sym_chan] = 114,
        [anon_sym_LT_DASH] = 116,
        [sym_identifier] = 118,
        [sym_comment] = 8,
    },
    [264] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 590,
        [sym_comment] = 8,
    },
    [265] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 680,
        [sym_comment] = 8,
    },
    [266] = {
        [anon_sym_RPAREN] = 682,
        [sym_comment] = 8,
    },
    [267] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 684,
        [sym_comment] = 8,
    },
    [268] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 686,
        [sym_comment] = 8,
    },
    [269] = {
        [sym_type_spec] = 92,
        [aux_sym_type_declaration_repeat1] = 688,
        [anon_sym_RPAREN] = 690,
        [sym_identifier] = 88,
        [sym_comment] = 8,
    },
    [270] = {
        [anon_sym_RPAREN] = 692,
        [sym_comment] = 8,
    },
    [271] = {
        [sym_identifier] = 694,
        [sym_comment] = 8,
    },
    [272] = {
        [sym__parameter_list] = 696,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 698,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [273] = {
        [sym_parameters] = 700,
        [anon_sym_LPAREN] = 702,
        [sym_comment] = 8,
    },
    [274] = {
        [sym_parameters] = 704,
        [sym__type] = 704,
        [sym_pointer_type] = 706,
        [sym_array_type] = 706,
        [sym_slice_type] = 706,
        [sym_struct_type] = 706,
        [sym_interface_type] = 706,
        [sym_map_type] = 706,
        [sym_channel_type] = 706,
        [sym_function_type] = 706,
        [sym_block] = 708,
        [sym_qualified_identifier] = 706,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 710,
        [anon_sym_LPAREN] = 712,
        [anon_sym_func] = 714,
        [anon_sym_STAR] = 716,
        [anon_sym_LBRACK] = 718,
        [anon_sym_struct] = 720,
        [anon_sym_LBRACE] = 722,
        [anon_sym_interface] = 724,
        [anon_sym_map] = 726,
        [anon_sym_chan] = 728,
        [anon_sym_LT_DASH] = 730,
        [sym_identifier] = 732,
        [sym_comment] = 8,
    },
    [275] = {
        [sym__parameter_list] = 734,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 736,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [276] = {
        [anon_sym_RPAREN] = 738,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [277] = {
        [sym_parameters] = 272,
        [sym__type] = 272,
        [sym_pointer_type] = 272,
        [sym_array_type] = 272,
        [sym_slice_type] = 272,
        [sym_struct_type] = 272,
        [sym_interface_type] = 272,
        [sym_map_type] = 272,
        [sym_channel_type] = 272,
        [sym_function_type] = 272,
        [sym_block] = 272,
        [sym_qualified_identifier] = 272,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 272,
        [anon_sym_LPAREN] = 272,
        [anon_sym_func] = 272,
        [anon_sym_STAR] = 272,
        [anon_sym_LBRACK] = 272,
        [anon_sym_struct] = 272,
        [anon_sym_LBRACE] = 272,
        [anon_sym_interface] = 272,
        [anon_sym_map] = 272,
        [anon_sym_chan] = 272,
        [anon_sym_LT_DASH] = 272,
        [sym_identifier] = 272,
        [sym_comment] = 8,
    },
    [278] = {
        [sym_parameters] = 582,
        [sym__type] = 582,
        [sym_pointer_type] = 582,
        [sym_array_type] = 582,
        [sym_slice_type] = 582,
        [sym_struct_type] = 582,
        [sym_interface_type] = 582,
        [sym_map_type] = 582,
        [sym_channel_type] = 582,
        [sym_function_type] = 582,
        [sym_block] = 582,
        [sym_qualified_identifier] = 582,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 582,
        [anon_sym_LPAREN] = 582,
        [anon_sym_func] = 582,
        [anon_sym_STAR] = 582,
        [anon_sym_LBRACK] = 582,
        [anon_sym_struct] = 582,
        [anon_sym_LBRACE] = 582,
        [anon_sym_interface] = 582,
        [anon_sym_map] = 582,
        [anon_sym_chan] = 582,
        [anon_sym_LT_DASH] = 582,
        [sym_identifier] = 582,
        [sym_comment] = 8,
    },
    [279] = {
        [sym_block] = 740,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 742,
        [anon_sym_LBRACE] = 722,
        [sym_comment] = 8,
    },
    [280] = {
        [sym_block] = 122,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 122,
        [anon_sym_LBRACE] = 122,
        [sym_comment] = 8,
    },
    [281] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 742,
        [sym_comment] = 8,
    },
    [282] = {
        [sym__parameter_list] = 744,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 746,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [283] = {
        [sym_parameters] = 748,
        [anon_sym_LPAREN] = 702,
        [sym_comment] = 8,
    },
    [284] = {
        [sym__type] = 750,
        [sym_pointer_type] = 706,
        [sym_array_type] = 706,
        [sym_slice_type] = 706,
        [sym_struct_type] = 706,
        [sym_interface_type] = 706,
        [sym_map_type] = 706,
        [sym_channel_type] = 706,
        [sym_function_type] = 706,
        [sym_qualified_identifier] = 706,
        [anon_sym_func] = 714,
        [anon_sym_STAR] = 716,
        [anon_sym_LBRACK] = 718,
        [anon_sym_struct] = 720,
        [anon_sym_interface] = 724,
        [anon_sym_map] = 726,
        [anon_sym_chan] = 728,
        [anon_sym_LT_DASH] = 730,
        [sym_identifier] = 732,
        [sym_comment] = 8,
    },
    [285] = {
        [sym__expression] = 752,
        [sym_call_expression] = 132,
        [sym_unary_expression] = 132,
        [sym_binary_expression] = 132,
        [sym__primary_expression] = 132,
        [sym__string_literal] = 134,
        [sym_int_literal] = 134,
        [sym_float_literal] = 134,
        [anon_sym_RBRACK] = 754,
        [sym_identifier] = 134,
        [sym_raw_string_literal] = 138,
        [sym_interpreted_string_literal] = 138,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 140,
        [sym_comment] = 8,
    },
    [286] = {
        [anon_sym_LBRACE] = 756,
        [sym_comment] = 8,
    },
    [287] = {
        [sym__declaration] = 758,
        [sym_const_declaration] = 18,
        [sym_var_declaration] = 18,
        [sym_type_declaration] = 18,
        [sym__statement] = 760,
        [sym__expression] = 762,
        [sym_call_expression] = 764,
        [sym_unary_expression] = 764,
        [sym_binary_expression] = 764,
        [sym__primary_expression] = 764,
        [sym__string_literal] = 766,
        [sym_int_literal] = 766,
        [sym_float_literal] = 766,
        [aux_sym_block_repeat1] = 768,
        [anon_sym_const] = 28,
        [anon_sym_var] = 30,
        [anon_sym_type] = 34,
        [anon_sym_RBRACE] = 770,
        [sym_identifier] = 766,
        [sym_raw_string_literal] = 772,
        [sym_interpreted_string_literal] = 772,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 774,
        [sym_comment] = 8,
    },
    [288] = {
        [anon_sym_LBRACE] = 776,
        [sym_comment] = 8,
    },
    [289] = {
        [anon_sym_LBRACK] = 778,
        [sym_comment] = 8,
    },
    [290] = {
        [sym__type] = 780,
        [sym_pointer_type] = 706,
        [sym_array_type] = 706,
        [sym_slice_type] = 706,
        [sym_struct_type] = 706,
        [sym_interface_type] = 706,
        [sym_map_type] = 706,
        [sym_channel_type] = 706,
        [sym_function_type] = 706,
        [sym_qualified_identifier] = 706,
        [anon_sym_func] = 714,
        [anon_sym_STAR] = 716,
        [anon_sym_LBRACK] = 718,
        [anon_sym_struct] = 720,
        [anon_sym_interface] = 724,
        [anon_sym_map] = 726,
        [anon_sym_chan] = 728,
        [anon_sym_LT_DASH] = 782,
        [sym_identifier] = 732,
        [sym_comment] = 8,
    },
    [291] = {
        [anon_sym_chan] = 784,
        [sym_comment] = 8,
    },
    [292] = {
        [sym_block] = 122,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 122,
        [anon_sym_DOT] = 786,
        [anon_sym_LBRACE] = 122,
        [sym_comment] = 8,
    },
    [293] = {
        [sym_identifier] = 788,
        [sym_comment] = 8,
    },
    [294] = {
        [sym_block] = 158,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 158,
        [anon_sym_LBRACE] = 158,
        [sym_comment] = 8,
    },
    [295] = {
        [sym__type] = 790,
        [sym_pointer_type] = 706,
        [sym_array_type] = 706,
        [sym_slice_type] = 706,
        [sym_struct_type] = 706,
        [sym_interface_type] = 706,
        [sym_map_type] = 706,
        [sym_channel_type] = 706,
        [sym_function_type] = 706,
        [sym_qualified_identifier] = 706,
        [anon_sym_func] = 714,
        [anon_sym_STAR] = 716,
        [anon_sym_LBRACK] = 718,
        [anon_sym_struct] = 720,
        [anon_sym_interface] = 724,
        [anon_sym_map] = 726,
        [anon_sym_chan] = 728,
        [anon_sym_LT_DASH] = 730,
        [sym_identifier] = 732,
        [sym_comment] = 8,
    },
    [296] = {
        [sym_block] = 162,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 162,
        [anon_sym_LBRACE] = 162,
        [sym_comment] = 8,
    },
    [297] = {
        [sym_block] = 164,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 164,
        [anon_sym_LBRACE] = 164,
        [sym_comment] = 8,
    },
    [298] = {
        [sym__type] = 792,
        [sym_pointer_type] = 706,
        [sym_array_type] = 706,
        [sym_slice_type] = 706,
        [sym_struct_type] = 706,
        [sym_interface_type] = 706,
        [sym_map_type] = 706,
        [sym_channel_type] = 706,
        [sym_function_type] = 706,
        [sym_qualified_identifier] = 706,
        [anon_sym_func] = 714,
        [anon_sym_STAR] = 716,
        [anon_sym_LBRACK] = 718,
        [anon_sym_struct] = 720,
        [anon_sym_interface] = 724,
        [anon_sym_map] = 726,
        [anon_sym_chan] = 728,
        [anon_sym_LT_DASH] = 730,
        [sym_identifier] = 732,
        [sym_comment] = 8,
    },
    [299] = {
        [sym_block] = 168,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 168,
        [anon_sym_LBRACE] = 168,
        [sym_comment] = 8,
    },
    [300] = {
        [sym__type] = 794,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [301] = {
        [anon_sym_RBRACK] = 796,
        [sym_comment] = 8,
    },
    [302] = {
        [sym__type] = 798,
        [sym_pointer_type] = 706,
        [sym_array_type] = 706,
        [sym_slice_type] = 706,
        [sym_struct_type] = 706,
        [sym_interface_type] = 706,
        [sym_map_type] = 706,
        [sym_channel_type] = 706,
        [sym_function_type] = 706,
        [sym_qualified_identifier] = 706,
        [anon_sym_func] = 714,
        [anon_sym_STAR] = 716,
        [anon_sym_LBRACK] = 718,
        [anon_sym_struct] = 720,
        [anon_sym_interface] = 724,
        [anon_sym_map] = 726,
        [anon_sym_chan] = 728,
        [anon_sym_LT_DASH] = 730,
        [sym_identifier] = 732,
        [sym_comment] = 8,
    },
    [303] = {
        [sym_block] = 230,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 230,
        [anon_sym_LBRACE] = 230,
        [sym_comment] = 8,
    },
    [304] = {
        [sym_method_spec] = 232,
        [aux_sym_interface_type_repeat1] = 800,
        [anon_sym_RBRACE] = 802,
        [sym_identifier] = 238,
        [sym_comment] = 8,
    },
    [305] = {
        [anon_sym_RBRACE] = 804,
        [sym_comment] = 8,
    },
    [306] = {
        [sym_block] = 244,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 244,
        [anon_sym_LBRACE] = 244,
        [sym_comment] = 8,
    },
    [307] = {
        [sym_block] = 340,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 340,
        [anon_sym_LBRACE] = 340,
        [sym_comment] = 8,
    },
    [308] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 806,
        [sym_comment] = 8,
    },
    [309] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 808,
        [sym_comment] = 8,
    },
    [310] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 806,
        [anon_sym_LPAREN] = 810,
        [anon_sym_STAR] = 812,
        [anon_sym_SLASH] = 812,
        [anon_sym_PERCENT] = 812,
        [anon_sym_LT_LT] = 812,
        [anon_sym_GT_GT] = 812,
        [anon_sym_AMP] = 812,
        [anon_sym_AMP_CARET] = 812,
        [anon_sym_PLUS] = 814,
        [anon_sym_DASH] = 814,
        [anon_sym_PIPE] = 814,
        [anon_sym_CARET] = 814,
        [anon_sym_EQ_EQ] = 816,
        [anon_sym_BANG_EQ] = 816,
        [anon_sym_LT] = 816,
        [anon_sym_LT_EQ] = 816,
        [anon_sym_GT] = 816,
        [anon_sym_GT_EQ] = 816,
        [anon_sym_AMP_AMP] = 818,
        [anon_sym_PIPE_PIPE] = 820,
        [sym_comment] = 8,
    },
    [311] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 482,
        [anon_sym_LPAREN] = 482,
        [anon_sym_STAR] = 482,
        [anon_sym_SLASH] = 482,
        [anon_sym_PERCENT] = 482,
        [anon_sym_LT_LT] = 482,
        [anon_sym_GT_GT] = 482,
        [anon_sym_AMP] = 482,
        [anon_sym_AMP_CARET] = 482,
        [anon_sym_PLUS] = 482,
        [anon_sym_DASH] = 482,
        [anon_sym_PIPE] = 482,
        [anon_sym_CARET] = 482,
        [anon_sym_EQ_EQ] = 482,
        [anon_sym_BANG_EQ] = 482,
        [anon_sym_LT] = 482,
        [anon_sym_LT_EQ] = 482,
        [anon_sym_GT] = 482,
        [anon_sym_GT_EQ] = 482,
        [anon_sym_AMP_AMP] = 482,
        [anon_sym_PIPE_PIPE] = 482,
        [sym_comment] = 8,
    },
    [312] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 484,
        [anon_sym_LPAREN] = 484,
        [anon_sym_STAR] = 484,
        [anon_sym_SLASH] = 484,
        [anon_sym_PERCENT] = 484,
        [anon_sym_LT_LT] = 484,
        [anon_sym_GT_GT] = 484,
        [anon_sym_AMP] = 484,
        [anon_sym_AMP_CARET] = 484,
        [anon_sym_PLUS] = 484,
        [anon_sym_DASH] = 484,
        [anon_sym_PIPE] = 484,
        [anon_sym_CARET] = 484,
        [anon_sym_EQ_EQ] = 484,
        [anon_sym_BANG_EQ] = 484,
        [anon_sym_LT] = 484,
        [anon_sym_LT_EQ] = 484,
        [anon_sym_GT] = 484,
        [anon_sym_GT_EQ] = 484,
        [anon_sym_AMP_AMP] = 484,
        [anon_sym_PIPE_PIPE] = 484,
        [sym_comment] = 8,
    },
    [313] = {
        [anon_sym_RBRACE] = 822,
        [sym_comment] = 8,
    },
    [314] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 824,
        [sym_comment] = 8,
    },
    [315] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 400,
        [anon_sym_LPAREN] = 400,
        [anon_sym_STAR] = 400,
        [anon_sym_SLASH] = 400,
        [anon_sym_PERCENT] = 400,
        [anon_sym_LT_LT] = 400,
        [anon_sym_GT_GT] = 400,
        [anon_sym_AMP] = 400,
        [anon_sym_AMP_CARET] = 400,
        [anon_sym_PLUS] = 400,
        [anon_sym_DASH] = 400,
        [anon_sym_PIPE] = 400,
        [anon_sym_CARET] = 400,
        [anon_sym_EQ_EQ] = 400,
        [anon_sym_BANG_EQ] = 400,
        [anon_sym_LT] = 400,
        [anon_sym_LT_EQ] = 400,
        [anon_sym_GT] = 400,
        [anon_sym_GT_EQ] = 400,
        [anon_sym_AMP_AMP] = 400,
        [anon_sym_PIPE_PIPE] = 400,
        [sym_comment] = 8,
    },
    [316] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 488,
        [anon_sym_LPAREN] = 488,
        [anon_sym_STAR] = 488,
        [anon_sym_SLASH] = 488,
        [anon_sym_PERCENT] = 488,
        [anon_sym_LT_LT] = 488,
        [anon_sym_GT_GT] = 488,
        [anon_sym_AMP] = 488,
        [anon_sym_AMP_CARET] = 488,
        [anon_sym_PLUS] = 488,
        [anon_sym_DASH] = 488,
        [anon_sym_PIPE] = 488,
        [anon_sym_CARET] = 488,
        [anon_sym_EQ_EQ] = 488,
        [anon_sym_BANG_EQ] = 488,
        [anon_sym_LT] = 488,
        [anon_sym_LT_EQ] = 488,
        [anon_sym_GT] = 488,
        [anon_sym_GT_EQ] = 488,
        [anon_sym_AMP_AMP] = 488,
        [anon_sym_PIPE_PIPE] = 488,
        [sym_comment] = 8,
    },
    [317] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 826,
        [sym_comment] = 8,
    },
    [318] = {
        [sym_expression_list] = 828,
        [sym__expression] = 494,
        [sym_call_expression] = 496,
        [sym_unary_expression] = 496,
        [sym_binary_expression] = 496,
        [sym__primary_expression] = 496,
        [sym__string_literal] = 498,
        [sym_int_literal] = 498,
        [sym_float_literal] = 498,
        [sym_identifier] = 498,
        [sym_raw_string_literal] = 500,
        [sym_interpreted_string_literal] = 500,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 502,
        [sym_comment] = 8,
    },
    [319] = {
        [sym__expression] = 830,
        [sym_call_expression] = 764,
        [sym_unary_expression] = 764,
        [sym_binary_expression] = 764,
        [sym__primary_expression] = 764,
        [sym__string_literal] = 766,
        [sym_int_literal] = 766,
        [sym_float_literal] = 766,
        [sym_identifier] = 766,
        [sym_raw_string_literal] = 772,
        [sym_interpreted_string_literal] = 772,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 774,
        [sym_comment] = 8,
    },
    [320] = {
        [sym__expression] = 832,
        [sym_call_expression] = 764,
        [sym_unary_expression] = 764,
        [sym_binary_expression] = 764,
        [sym__primary_expression] = 764,
        [sym__string_literal] = 766,
        [sym_int_literal] = 766,
        [sym_float_literal] = 766,
        [sym_identifier] = 766,
        [sym_raw_string_literal] = 772,
        [sym_interpreted_string_literal] = 772,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 774,
        [sym_comment] = 8,
    },
    [321] = {
        [sym__expression] = 834,
        [sym_call_expression] = 764,
        [sym_unary_expression] = 764,
        [sym_binary_expression] = 764,
        [sym__primary_expression] = 764,
        [sym__string_literal] = 766,
        [sym_int_literal] = 766,
        [sym_float_literal] = 766,
        [sym_identifier] = 766,
        [sym_raw_string_literal] = 772,
        [sym_interpreted_string_literal] = 772,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 774,
        [sym_comment] = 8,
    },
    [322] = {
        [sym__expression] = 836,
        [sym_call_expression] = 764,
        [sym_unary_expression] = 764,
        [sym_binary_expression] = 764,
        [sym__primary_expression] = 764,
        [sym__string_literal] = 766,
        [sym_int_literal] = 766,
        [sym_float_literal] = 766,
        [sym_identifier] = 766,
        [sym_raw_string_literal] = 772,
        [sym_interpreted_string_literal] = 772,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 774,
        [sym_comment] = 8,
    },
    [323] = {
        [sym__expression] = 838,
        [sym_call_expression] = 764,
        [sym_unary_expression] = 764,
        [sym_binary_expression] = 764,
        [sym__primary_expression] = 764,
        [sym__string_literal] = 766,
        [sym_int_literal] = 766,
        [sym_float_literal] = 766,
        [sym_identifier] = 766,
        [sym_raw_string_literal] = 772,
        [sym_interpreted_string_literal] = 772,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 774,
        [sym_comment] = 8,
    },
    [324] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 516,
        [anon_sym_LPAREN] = 516,
        [anon_sym_STAR] = 812,
        [anon_sym_SLASH] = 812,
        [anon_sym_PERCENT] = 812,
        [anon_sym_LT_LT] = 812,
        [anon_sym_GT_GT] = 812,
        [anon_sym_AMP] = 812,
        [anon_sym_AMP_CARET] = 812,
        [anon_sym_PLUS] = 814,
        [anon_sym_DASH] = 814,
        [anon_sym_PIPE] = 814,
        [anon_sym_CARET] = 814,
        [anon_sym_EQ_EQ] = 816,
        [anon_sym_BANG_EQ] = 816,
        [anon_sym_LT] = 816,
        [anon_sym_LT_EQ] = 816,
        [anon_sym_GT] = 816,
        [anon_sym_GT_EQ] = 816,
        [anon_sym_AMP_AMP] = 818,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [325] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 516,
        [anon_sym_LPAREN] = 516,
        [anon_sym_STAR] = 812,
        [anon_sym_SLASH] = 812,
        [anon_sym_PERCENT] = 812,
        [anon_sym_LT_LT] = 812,
        [anon_sym_GT_GT] = 812,
        [anon_sym_AMP] = 812,
        [anon_sym_AMP_CARET] = 812,
        [anon_sym_PLUS] = 814,
        [anon_sym_DASH] = 814,
        [anon_sym_PIPE] = 814,
        [anon_sym_CARET] = 814,
        [anon_sym_EQ_EQ] = 816,
        [anon_sym_BANG_EQ] = 816,
        [anon_sym_LT] = 816,
        [anon_sym_LT_EQ] = 816,
        [anon_sym_GT] = 816,
        [anon_sym_GT_EQ] = 816,
        [anon_sym_AMP_AMP] = 516,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [326] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 516,
        [anon_sym_LPAREN] = 516,
        [anon_sym_STAR] = 812,
        [anon_sym_SLASH] = 812,
        [anon_sym_PERCENT] = 812,
        [anon_sym_LT_LT] = 812,
        [anon_sym_GT_GT] = 812,
        [anon_sym_AMP] = 812,
        [anon_sym_AMP_CARET] = 812,
        [anon_sym_PLUS] = 814,
        [anon_sym_DASH] = 814,
        [anon_sym_PIPE] = 814,
        [anon_sym_CARET] = 814,
        [anon_sym_EQ_EQ] = 516,
        [anon_sym_BANG_EQ] = 516,
        [anon_sym_LT] = 516,
        [anon_sym_LT_EQ] = 516,
        [anon_sym_GT] = 516,
        [anon_sym_GT_EQ] = 516,
        [anon_sym_AMP_AMP] = 516,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [327] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 516,
        [anon_sym_LPAREN] = 516,
        [anon_sym_STAR] = 812,
        [anon_sym_SLASH] = 812,
        [anon_sym_PERCENT] = 812,
        [anon_sym_LT_LT] = 812,
        [anon_sym_GT_GT] = 812,
        [anon_sym_AMP] = 812,
        [anon_sym_AMP_CARET] = 812,
        [anon_sym_PLUS] = 516,
        [anon_sym_DASH] = 516,
        [anon_sym_PIPE] = 516,
        [anon_sym_CARET] = 516,
        [anon_sym_EQ_EQ] = 516,
        [anon_sym_BANG_EQ] = 516,
        [anon_sym_LT] = 516,
        [anon_sym_LT_EQ] = 516,
        [anon_sym_GT] = 516,
        [anon_sym_GT_EQ] = 516,
        [anon_sym_AMP_AMP] = 516,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [328] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 518,
        [anon_sym_LPAREN] = 518,
        [anon_sym_STAR] = 518,
        [anon_sym_SLASH] = 518,
        [anon_sym_PERCENT] = 518,
        [anon_sym_LT_LT] = 518,
        [anon_sym_GT_GT] = 518,
        [anon_sym_AMP] = 518,
        [anon_sym_AMP_CARET] = 518,
        [anon_sym_PLUS] = 518,
        [anon_sym_DASH] = 518,
        [anon_sym_PIPE] = 518,
        [anon_sym_CARET] = 518,
        [anon_sym_EQ_EQ] = 518,
        [anon_sym_BANG_EQ] = 518,
        [anon_sym_LT] = 518,
        [anon_sym_LT_EQ] = 518,
        [anon_sym_GT] = 518,
        [anon_sym_GT_EQ] = 518,
        [anon_sym_AMP_AMP] = 518,
        [anon_sym_PIPE_PIPE] = 518,
        [sym_comment] = 8,
    },
    [329] = {
        [anon_sym_RPAREN] = 840,
        [sym_comment] = 8,
    },
    [330] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 566,
        [anon_sym_LPAREN] = 566,
        [anon_sym_STAR] = 566,
        [anon_sym_SLASH] = 566,
        [anon_sym_PERCENT] = 566,
        [anon_sym_LT_LT] = 566,
        [anon_sym_GT_GT] = 566,
        [anon_sym_AMP] = 566,
        [anon_sym_AMP_CARET] = 566,
        [anon_sym_PLUS] = 566,
        [anon_sym_DASH] = 566,
        [anon_sym_PIPE] = 566,
        [anon_sym_CARET] = 566,
        [anon_sym_EQ_EQ] = 566,
        [anon_sym_BANG_EQ] = 566,
        [anon_sym_LT] = 566,
        [anon_sym_LT_EQ] = 566,
        [anon_sym_GT] = 566,
        [anon_sym_GT_EQ] = 566,
        [anon_sym_AMP_AMP] = 566,
        [anon_sym_PIPE_PIPE] = 566,
        [sym_comment] = 8,
    },
    [331] = {
        [sym__declaration] = 758,
        [sym_const_declaration] = 18,
        [sym_var_declaration] = 18,
        [sym_type_declaration] = 18,
        [sym__statement] = 760,
        [sym__expression] = 762,
        [sym_call_expression] = 764,
        [sym_unary_expression] = 764,
        [sym_binary_expression] = 764,
        [sym__primary_expression] = 764,
        [sym__string_literal] = 766,
        [sym_int_literal] = 766,
        [sym_float_literal] = 766,
        [aux_sym_block_repeat1] = 842,
        [anon_sym_const] = 28,
        [anon_sym_var] = 30,
        [anon_sym_type] = 34,
        [anon_sym_RBRACE] = 844,
        [sym_identifier] = 766,
        [sym_raw_string_literal] = 772,
        [sym_interpreted_string_literal] = 772,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 774,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 774,
        [sym_comment] = 8,
    },
    [332] = {
        [anon_sym_RBRACE] = 846,
        [sym_comment] = 8,
    },
    [333] = {
        [sym_identifier_list] = 342,
        [sym_field_declaration] = 344,
        [aux_sym_struct_type_repeat1] = 848,
        [anon_sym_STAR] = 348,
        [anon_sym_RBRACE] = 850,
        [sym_identifier] = 352,
        [sym_comment] = 8,
    },
    [334] = {
        [anon_sym_RBRACE] = 852,
        [sym_comment] = 8,
    },
    [335] = {
        [sym_block] = 380,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 380,
        [anon_sym_LBRACE] = 380,
        [sym_comment] = 8,
    },
    [336] = {
        [sym_block] = 412,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 412,
        [anon_sym_LBRACE] = 412,
        [sym_comment] = 8,
    },
    [337] = {
        [anon_sym_LPAREN] = 468,
        [anon_sym_STAR] = 470,
        [anon_sym_RBRACK] = 854,
        [anon_sym_SLASH] = 470,
        [anon_sym_PERCENT] = 470,
        [anon_sym_LT_LT] = 470,
        [anon_sym_GT_GT] = 470,
        [anon_sym_AMP] = 470,
        [anon_sym_AMP_CARET] = 470,
        [anon_sym_PLUS] = 474,
        [anon_sym_DASH] = 474,
        [anon_sym_PIPE] = 474,
        [anon_sym_CARET] = 474,
        [anon_sym_EQ_EQ] = 476,
        [anon_sym_BANG_EQ] = 476,
        [anon_sym_LT] = 476,
        [anon_sym_LT_EQ] = 476,
        [anon_sym_GT] = 476,
        [anon_sym_GT_EQ] = 476,
        [anon_sym_AMP_AMP] = 478,
        [anon_sym_PIPE_PIPE] = 480,
        [sym_comment] = 8,
    },
    [338] = {
        [sym__type] = 856,
        [sym_pointer_type] = 706,
        [sym_array_type] = 706,
        [sym_slice_type] = 706,
        [sym_struct_type] = 706,
        [sym_interface_type] = 706,
        [sym_map_type] = 706,
        [sym_channel_type] = 706,
        [sym_function_type] = 706,
        [sym_qualified_identifier] = 706,
        [anon_sym_func] = 714,
        [anon_sym_STAR] = 716,
        [anon_sym_LBRACK] = 718,
        [anon_sym_struct] = 720,
        [anon_sym_interface] = 724,
        [anon_sym_map] = 726,
        [anon_sym_chan] = 728,
        [anon_sym_LT_DASH] = 730,
        [sym_identifier] = 732,
        [sym_comment] = 8,
    },
    [339] = {
        [sym_block] = 490,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 490,
        [anon_sym_LBRACE] = 490,
        [sym_comment] = 8,
    },
    [340] = {
        [sym__type] = 858,
        [sym_pointer_type] = 706,
        [sym_array_type] = 706,
        [sym_slice_type] = 706,
        [sym_struct_type] = 706,
        [sym_interface_type] = 706,
        [sym_map_type] = 706,
        [sym_channel_type] = 706,
        [sym_function_type] = 706,
        [sym_qualified_identifier] = 706,
        [anon_sym_func] = 714,
        [anon_sym_STAR] = 716,
        [anon_sym_LBRACK] = 718,
        [anon_sym_struct] = 720,
        [anon_sym_interface] = 724,
        [anon_sym_map] = 726,
        [anon_sym_chan] = 728,
        [anon_sym_LT_DASH] = 730,
        [sym_identifier] = 732,
        [sym_comment] = 8,
    },
    [341] = {
        [sym_block] = 520,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 520,
        [anon_sym_LBRACE] = 520,
        [sym_comment] = 8,
    },
    [342] = {
        [sym_block] = 568,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 568,
        [anon_sym_LBRACE] = 568,
        [sym_comment] = 8,
    },
    [343] = {
        [sym_parameters] = 860,
        [sym__type] = 860,
        [sym_pointer_type] = 706,
        [sym_array_type] = 706,
        [sym_slice_type] = 706,
        [sym_struct_type] = 706,
        [sym_interface_type] = 706,
        [sym_map_type] = 706,
        [sym_channel_type] = 706,
        [sym_function_type] = 706,
        [sym_block] = 572,
        [sym_qualified_identifier] = 706,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 572,
        [anon_sym_LPAREN] = 712,
        [anon_sym_func] = 714,
        [anon_sym_STAR] = 716,
        [anon_sym_LBRACK] = 718,
        [anon_sym_struct] = 720,
        [anon_sym_LBRACE] = 572,
        [anon_sym_interface] = 724,
        [anon_sym_map] = 726,
        [anon_sym_chan] = 728,
        [anon_sym_LT_DASH] = 730,
        [sym_identifier] = 732,
        [sym_comment] = 8,
    },
    [344] = {
        [sym_block] = 590,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 590,
        [anon_sym_LBRACE] = 590,
        [sym_comment] = 8,
    },
    [345] = {
        [anon_sym_RPAREN] = 862,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [346] = {
        [sym_block] = 272,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 272,
        [anon_sym_LBRACE] = 272,
        [sym_comment] = 8,
    },
    [347] = {
        [sym_block] = 582,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 582,
        [anon_sym_LBRACE] = 582,
        [sym_comment] = 8,
    },
    [348] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 864,
        [sym_comment] = 8,
    },
    [349] = {
        [anon_sym_RPAREN] = 866,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [350] = {
        [sym_identifier] = 272,
        [sym_comment] = 8,
    },
    [351] = {
        [sym_identifier] = 582,
        [sym_comment] = 8,
    },
    [352] = {
        [sym_parameters] = 868,
        [anon_sym_LPAREN] = 702,
        [sym_comment] = 8,
    },
    [353] = {
        [sym_parameters] = 870,
        [sym__type] = 870,
        [sym_pointer_type] = 706,
        [sym_array_type] = 706,
        [sym_slice_type] = 706,
        [sym_struct_type] = 706,
        [sym_interface_type] = 706,
        [sym_map_type] = 706,
        [sym_channel_type] = 706,
        [sym_function_type] = 706,
        [sym_block] = 872,
        [sym_qualified_identifier] = 706,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 874,
        [anon_sym_LPAREN] = 712,
        [anon_sym_func] = 714,
        [anon_sym_STAR] = 716,
        [anon_sym_LBRACK] = 718,
        [anon_sym_struct] = 720,
        [anon_sym_LBRACE] = 722,
        [anon_sym_interface] = 724,
        [anon_sym_map] = 726,
        [anon_sym_chan] = 728,
        [anon_sym_LT_DASH] = 730,
        [sym_identifier] = 732,
        [sym_comment] = 8,
    },
    [354] = {
        [sym_block] = 876,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 878,
        [anon_sym_LBRACE] = 722,
        [sym_comment] = 8,
    },
    [355] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 878,
        [sym_comment] = 8,
    },
    [356] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 880,
        [sym_comment] = 8,
    },
    [357] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 882,
        [sym_comment] = 8,
    },
    [358] = {
        [sym__type] = 884,
        [sym_pointer_type] = 886,
        [sym_array_type] = 886,
        [sym_slice_type] = 886,
        [sym_struct_type] = 886,
        [sym_interface_type] = 886,
        [sym_map_type] = 886,
        [sym_channel_type] = 886,
        [sym_function_type] = 886,
        [sym_qualified_identifier] = 886,
        [anon_sym_EQ] = 888,
        [anon_sym_func] = 890,
        [anon_sym_STAR] = 892,
        [anon_sym_LBRACK] = 894,
        [anon_sym_struct] = 896,
        [anon_sym_interface] = 898,
        [anon_sym_map] = 900,
        [anon_sym_chan] = 902,
        [anon_sym_LT_DASH] = 904,
        [sym_identifier] = 906,
        [sym_comment] = 8,
    },
    [359] = {
        [sym_var_spec] = 908,
        [sym_identifier_list] = 74,
        [aux_sym_var_declaration_repeat1] = 910,
        [anon_sym_RPAREN] = 912,
        [sym_identifier] = 70,
        [sym_comment] = 8,
    },
    [360] = {
        [sym__type] = 382,
        [sym_pointer_type] = 382,
        [sym_array_type] = 382,
        [sym_slice_type] = 382,
        [sym_struct_type] = 382,
        [sym_interface_type] = 382,
        [sym_map_type] = 382,
        [sym_channel_type] = 382,
        [sym_function_type] = 382,
        [sym_qualified_identifier] = 382,
        [aux_sym_identifier_list_repeat1] = 914,
        [anon_sym_EQ] = 382,
        [anon_sym_func] = 382,
        [anon_sym_COMMA] = 916,
        [anon_sym_STAR] = 382,
        [anon_sym_LBRACK] = 382,
        [anon_sym_struct] = 382,
        [anon_sym_interface] = 382,
        [anon_sym_map] = 382,
        [anon_sym_chan] = 382,
        [anon_sym_LT_DASH] = 382,
        [sym_identifier] = 382,
        [sym_comment] = 8,
    },
    [361] = {
        [sym__type] = 396,
        [sym_pointer_type] = 396,
        [sym_array_type] = 396,
        [sym_slice_type] = 396,
        [sym_struct_type] = 396,
        [sym_interface_type] = 396,
        [sym_map_type] = 396,
        [sym_channel_type] = 396,
        [sym_function_type] = 396,
        [sym_qualified_identifier] = 396,
        [anon_sym_EQ] = 396,
        [anon_sym_func] = 396,
        [anon_sym_STAR] = 396,
        [anon_sym_LBRACK] = 396,
        [anon_sym_struct] = 396,
        [anon_sym_interface] = 396,
        [anon_sym_map] = 396,
        [anon_sym_chan] = 396,
        [anon_sym_LT_DASH] = 396,
        [sym_identifier] = 396,
        [sym_comment] = 8,
    },
    [362] = {
        [sym_identifier] = 918,
        [sym_comment] = 8,
    },
    [363] = {
        [sym__type] = 402,
        [sym_pointer_type] = 402,
        [sym_array_type] = 402,
        [sym_slice_type] = 402,
        [sym_struct_type] = 402,
        [sym_interface_type] = 402,
        [sym_map_type] = 402,
        [sym_channel_type] = 402,
        [sym_function_type] = 402,
        [sym_qualified_identifier] = 402,
        [aux_sym_identifier_list_repeat1] = 920,
        [anon_sym_EQ] = 402,
        [anon_sym_func] = 402,
        [anon_sym_COMMA] = 916,
        [anon_sym_STAR] = 402,
        [anon_sym_LBRACK] = 402,
        [anon_sym_struct] = 402,
        [anon_sym_interface] = 402,
        [anon_sym_map] = 402,
        [anon_sym_chan] = 402,
        [anon_sym_LT_DASH] = 402,
        [sym_identifier] = 402,
        [sym_comment] = 8,
    },
    [364] = {
        [sym__type] = 406,
        [sym_pointer_type] = 406,
        [sym_array_type] = 406,
        [sym_slice_type] = 406,
        [sym_struct_type] = 406,
        [sym_interface_type] = 406,
        [sym_map_type] = 406,
        [sym_channel_type] = 406,
        [sym_function_type] = 406,
        [sym_qualified_identifier] = 406,
        [anon_sym_EQ] = 406,
        [anon_sym_func] = 406,
        [anon_sym_STAR] = 406,
        [anon_sym_LBRACK] = 406,
        [anon_sym_struct] = 406,
        [anon_sym_interface] = 406,
        [anon_sym_map] = 406,
        [anon_sym_chan] = 406,
        [anon_sym_LT_DASH] = 406,
        [sym_identifier] = 406,
        [sym_comment] = 8,
    },
    [365] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 922,
        [sym_comment] = 8,
    },
    [366] = {
        [anon_sym_RPAREN] = 924,
        [sym_comment] = 8,
    },
    [367] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 926,
        [sym_comment] = 8,
    },
    [368] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 928,
        [sym_comment] = 8,
    },
    [369] = {
        [sym_var_spec] = 908,
        [sym_identifier_list] = 74,
        [aux_sym_var_declaration_repeat1] = 930,
        [anon_sym_RPAREN] = 932,
        [sym_identifier] = 70,
        [sym_comment] = 8,
    },
    [370] = {
        [anon_sym_RPAREN] = 934,
        [sym_comment] = 8,
    },
    [371] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 936,
        [anon_sym_EQ] = 938,
        [sym_comment] = 8,
    },
    [372] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 122,
        [anon_sym_EQ] = 122,
        [sym_comment] = 8,
    },
    [373] = {
        [sym_expression_list] = 940,
        [sym__expression] = 942,
        [sym_call_expression] = 944,
        [sym_unary_expression] = 944,
        [sym_binary_expression] = 944,
        [sym__primary_expression] = 944,
        [sym__string_literal] = 946,
        [sym_int_literal] = 946,
        [sym_float_literal] = 946,
        [sym_identifier] = 946,
        [sym_raw_string_literal] = 948,
        [sym_interpreted_string_literal] = 948,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 950,
        [sym_comment] = 8,
    },
    [374] = {
        [sym_parameters] = 952,
        [anon_sym_LPAREN] = 954,
        [sym_comment] = 8,
    },
    [375] = {
        [sym__type] = 956,
        [sym_pointer_type] = 886,
        [sym_array_type] = 886,
        [sym_slice_type] = 886,
        [sym_struct_type] = 886,
        [sym_interface_type] = 886,
        [sym_map_type] = 886,
        [sym_channel_type] = 886,
        [sym_function_type] = 886,
        [sym_qualified_identifier] = 886,
        [anon_sym_func] = 890,
        [anon_sym_STAR] = 892,
        [anon_sym_LBRACK] = 894,
        [anon_sym_struct] = 896,
        [anon_sym_interface] = 898,
        [anon_sym_map] = 900,
        [anon_sym_chan] = 902,
        [anon_sym_LT_DASH] = 904,
        [sym_identifier] = 906,
        [sym_comment] = 8,
    },
    [376] = {
        [sym__expression] = 958,
        [sym_call_expression] = 132,
        [sym_unary_expression] = 132,
        [sym_binary_expression] = 132,
        [sym__primary_expression] = 132,
        [sym__string_literal] = 134,
        [sym_int_literal] = 134,
        [sym_float_literal] = 134,
        [anon_sym_RBRACK] = 960,
        [sym_identifier] = 134,
        [sym_raw_string_literal] = 138,
        [sym_interpreted_string_literal] = 138,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 140,
        [sym_comment] = 8,
    },
    [377] = {
        [anon_sym_LBRACE] = 962,
        [sym_comment] = 8,
    },
    [378] = {
        [anon_sym_LBRACE] = 964,
        [sym_comment] = 8,
    },
    [379] = {
        [anon_sym_LBRACK] = 966,
        [sym_comment] = 8,
    },
    [380] = {
        [sym__type] = 968,
        [sym_pointer_type] = 886,
        [sym_array_type] = 886,
        [sym_slice_type] = 886,
        [sym_struct_type] = 886,
        [sym_interface_type] = 886,
        [sym_map_type] = 886,
        [sym_channel_type] = 886,
        [sym_function_type] = 886,
        [sym_qualified_identifier] = 886,
        [anon_sym_func] = 890,
        [anon_sym_STAR] = 892,
        [anon_sym_LBRACK] = 894,
        [anon_sym_struct] = 896,
        [anon_sym_interface] = 898,
        [anon_sym_map] = 900,
        [anon_sym_chan] = 902,
        [anon_sym_LT_DASH] = 970,
        [sym_identifier] = 906,
        [sym_comment] = 8,
    },
    [381] = {
        [anon_sym_chan] = 972,
        [sym_comment] = 8,
    },
    [382] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 122,
        [anon_sym_DOT] = 974,
        [anon_sym_EQ] = 122,
        [sym_comment] = 8,
    },
    [383] = {
        [sym_identifier] = 976,
        [sym_comment] = 8,
    },
    [384] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 158,
        [anon_sym_EQ] = 158,
        [sym_comment] = 8,
    },
    [385] = {
        [sym__type] = 978,
        [sym_pointer_type] = 886,
        [sym_array_type] = 886,
        [sym_slice_type] = 886,
        [sym_struct_type] = 886,
        [sym_interface_type] = 886,
        [sym_map_type] = 886,
        [sym_channel_type] = 886,
        [sym_function_type] = 886,
        [sym_qualified_identifier] = 886,
        [anon_sym_func] = 890,
        [anon_sym_STAR] = 892,
        [anon_sym_LBRACK] = 894,
        [anon_sym_struct] = 896,
        [anon_sym_interface] = 898,
        [anon_sym_map] = 900,
        [anon_sym_chan] = 902,
        [anon_sym_LT_DASH] = 904,
        [sym_identifier] = 906,
        [sym_comment] = 8,
    },
    [386] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 162,
        [anon_sym_EQ] = 162,
        [sym_comment] = 8,
    },
    [387] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 164,
        [anon_sym_EQ] = 164,
        [sym_comment] = 8,
    },
    [388] = {
        [sym__type] = 980,
        [sym_pointer_type] = 886,
        [sym_array_type] = 886,
        [sym_slice_type] = 886,
        [sym_struct_type] = 886,
        [sym_interface_type] = 886,
        [sym_map_type] = 886,
        [sym_channel_type] = 886,
        [sym_function_type] = 886,
        [sym_qualified_identifier] = 886,
        [anon_sym_func] = 890,
        [anon_sym_STAR] = 892,
        [anon_sym_LBRACK] = 894,
        [anon_sym_struct] = 896,
        [anon_sym_interface] = 898,
        [anon_sym_map] = 900,
        [anon_sym_chan] = 902,
        [anon_sym_LT_DASH] = 904,
        [sym_identifier] = 906,
        [sym_comment] = 8,
    },
    [389] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 168,
        [anon_sym_EQ] = 168,
        [sym_comment] = 8,
    },
    [390] = {
        [sym__type] = 982,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [391] = {
        [anon_sym_RBRACK] = 984,
        [sym_comment] = 8,
    },
    [392] = {
        [sym__type] = 986,
        [sym_pointer_type] = 886,
        [sym_array_type] = 886,
        [sym_slice_type] = 886,
        [sym_struct_type] = 886,
        [sym_interface_type] = 886,
        [sym_map_type] = 886,
        [sym_channel_type] = 886,
        [sym_function_type] = 886,
        [sym_qualified_identifier] = 886,
        [anon_sym_func] = 890,
        [anon_sym_STAR] = 892,
        [anon_sym_LBRACK] = 894,
        [anon_sym_struct] = 896,
        [anon_sym_interface] = 898,
        [anon_sym_map] = 900,
        [anon_sym_chan] = 902,
        [anon_sym_LT_DASH] = 904,
        [sym_identifier] = 906,
        [sym_comment] = 8,
    },
    [393] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 230,
        [anon_sym_EQ] = 230,
        [sym_comment] = 8,
    },
    [394] = {
        [sym_method_spec] = 232,
        [aux_sym_interface_type_repeat1] = 988,
        [anon_sym_RBRACE] = 990,
        [sym_identifier] = 238,
        [sym_comment] = 8,
    },
    [395] = {
        [anon_sym_RBRACE] = 992,
        [sym_comment] = 8,
    },
    [396] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 244,
        [anon_sym_EQ] = 244,
        [sym_comment] = 8,
    },
    [397] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 340,
        [anon_sym_EQ] = 340,
        [sym_comment] = 8,
    },
    [398] = {
        [sym_identifier_list] = 342,
        [sym_field_declaration] = 344,
        [aux_sym_struct_type_repeat1] = 994,
        [anon_sym_STAR] = 348,
        [anon_sym_RBRACE] = 996,
        [sym_identifier] = 352,
        [sym_comment] = 8,
    },
    [399] = {
        [anon_sym_RBRACE] = 998,
        [sym_comment] = 8,
    },
    [400] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 380,
        [anon_sym_EQ] = 380,
        [sym_comment] = 8,
    },
    [401] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 412,
        [anon_sym_EQ] = 412,
        [sym_comment] = 8,
    },
    [402] = {
        [anon_sym_LPAREN] = 468,
        [anon_sym_STAR] = 470,
        [anon_sym_RBRACK] = 1000,
        [anon_sym_SLASH] = 470,
        [anon_sym_PERCENT] = 470,
        [anon_sym_LT_LT] = 470,
        [anon_sym_GT_GT] = 470,
        [anon_sym_AMP] = 470,
        [anon_sym_AMP_CARET] = 470,
        [anon_sym_PLUS] = 474,
        [anon_sym_DASH] = 474,
        [anon_sym_PIPE] = 474,
        [anon_sym_CARET] = 474,
        [anon_sym_EQ_EQ] = 476,
        [anon_sym_BANG_EQ] = 476,
        [anon_sym_LT] = 476,
        [anon_sym_LT_EQ] = 476,
        [anon_sym_GT] = 476,
        [anon_sym_GT_EQ] = 476,
        [anon_sym_AMP_AMP] = 478,
        [anon_sym_PIPE_PIPE] = 480,
        [sym_comment] = 8,
    },
    [403] = {
        [sym__type] = 1002,
        [sym_pointer_type] = 886,
        [sym_array_type] = 886,
        [sym_slice_type] = 886,
        [sym_struct_type] = 886,
        [sym_interface_type] = 886,
        [sym_map_type] = 886,
        [sym_channel_type] = 886,
        [sym_function_type] = 886,
        [sym_qualified_identifier] = 886,
        [anon_sym_func] = 890,
        [anon_sym_STAR] = 892,
        [anon_sym_LBRACK] = 894,
        [anon_sym_struct] = 896,
        [anon_sym_interface] = 898,
        [anon_sym_map] = 900,
        [anon_sym_chan] = 902,
        [anon_sym_LT_DASH] = 904,
        [sym_identifier] = 906,
        [sym_comment] = 8,
    },
    [404] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 490,
        [anon_sym_EQ] = 490,
        [sym_comment] = 8,
    },
    [405] = {
        [sym__type] = 1004,
        [sym_pointer_type] = 886,
        [sym_array_type] = 886,
        [sym_slice_type] = 886,
        [sym_struct_type] = 886,
        [sym_interface_type] = 886,
        [sym_map_type] = 886,
        [sym_channel_type] = 886,
        [sym_function_type] = 886,
        [sym_qualified_identifier] = 886,
        [anon_sym_func] = 890,
        [anon_sym_STAR] = 892,
        [anon_sym_LBRACK] = 894,
        [anon_sym_struct] = 896,
        [anon_sym_interface] = 898,
        [anon_sym_map] = 900,
        [anon_sym_chan] = 902,
        [anon_sym_LT_DASH] = 904,
        [sym_identifier] = 906,
        [sym_comment] = 8,
    },
    [406] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 520,
        [anon_sym_EQ] = 520,
        [sym_comment] = 8,
    },
    [407] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 568,
        [anon_sym_EQ] = 568,
        [sym_comment] = 8,
    },
    [408] = {
        [sym_parameters] = 1006,
        [sym__type] = 1006,
        [sym_pointer_type] = 886,
        [sym_array_type] = 886,
        [sym_slice_type] = 886,
        [sym_struct_type] = 886,
        [sym_interface_type] = 886,
        [sym_map_type] = 886,
        [sym_channel_type] = 886,
        [sym_function_type] = 886,
        [sym_qualified_identifier] = 886,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 572,
        [anon_sym_LPAREN] = 1008,
        [anon_sym_EQ] = 572,
        [anon_sym_func] = 890,
        [anon_sym_STAR] = 892,
        [anon_sym_LBRACK] = 894,
        [anon_sym_struct] = 896,
        [anon_sym_interface] = 898,
        [anon_sym_map] = 900,
        [anon_sym_chan] = 902,
        [anon_sym_LT_DASH] = 904,
        [sym_identifier] = 906,
        [sym_comment] = 8,
    },
    [409] = {
        [sym__parameter_list] = 1010,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 1012,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [410] = {
        [anon_sym_RPAREN] = 1014,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [411] = {
        [sym_parameters] = 272,
        [sym__type] = 272,
        [sym_pointer_type] = 272,
        [sym_array_type] = 272,
        [sym_slice_type] = 272,
        [sym_struct_type] = 272,
        [sym_interface_type] = 272,
        [sym_map_type] = 272,
        [sym_channel_type] = 272,
        [sym_function_type] = 272,
        [sym_qualified_identifier] = 272,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 272,
        [anon_sym_LPAREN] = 272,
        [anon_sym_EQ] = 272,
        [anon_sym_func] = 272,
        [anon_sym_STAR] = 272,
        [anon_sym_LBRACK] = 272,
        [anon_sym_struct] = 272,
        [anon_sym_interface] = 272,
        [anon_sym_map] = 272,
        [anon_sym_chan] = 272,
        [anon_sym_LT_DASH] = 272,
        [sym_identifier] = 272,
        [sym_comment] = 8,
    },
    [412] = {
        [sym_parameters] = 582,
        [sym__type] = 582,
        [sym_pointer_type] = 582,
        [sym_array_type] = 582,
        [sym_slice_type] = 582,
        [sym_struct_type] = 582,
        [sym_interface_type] = 582,
        [sym_map_type] = 582,
        [sym_channel_type] = 582,
        [sym_function_type] = 582,
        [sym_qualified_identifier] = 582,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 582,
        [anon_sym_LPAREN] = 582,
        [anon_sym_EQ] = 582,
        [anon_sym_func] = 582,
        [anon_sym_STAR] = 582,
        [anon_sym_LBRACK] = 582,
        [anon_sym_struct] = 582,
        [anon_sym_interface] = 582,
        [anon_sym_map] = 582,
        [anon_sym_chan] = 582,
        [anon_sym_LT_DASH] = 582,
        [sym_identifier] = 582,
        [sym_comment] = 8,
    },
    [413] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 590,
        [anon_sym_EQ] = 590,
        [sym_comment] = 8,
    },
    [414] = {
        [sym__parameter_list] = 1016,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 1018,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [415] = {
        [anon_sym_RPAREN] = 1020,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [416] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 272,
        [anon_sym_EQ] = 272,
        [sym_comment] = 8,
    },
    [417] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 582,
        [anon_sym_EQ] = 582,
        [sym_comment] = 8,
    },
    [418] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 1022,
        [sym_comment] = 8,
    },
    [419] = {
        [aux_sym_expression_list_repeat1] = 1024,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 528,
        [anon_sym_LPAREN] = 1026,
        [anon_sym_COMMA] = 1028,
        [anon_sym_STAR] = 1030,
        [anon_sym_SLASH] = 1030,
        [anon_sym_PERCENT] = 1030,
        [anon_sym_LT_LT] = 1030,
        [anon_sym_GT_GT] = 1030,
        [anon_sym_AMP] = 1030,
        [anon_sym_AMP_CARET] = 1030,
        [anon_sym_PLUS] = 1032,
        [anon_sym_DASH] = 1032,
        [anon_sym_PIPE] = 1032,
        [anon_sym_CARET] = 1032,
        [anon_sym_EQ_EQ] = 1034,
        [anon_sym_BANG_EQ] = 1034,
        [anon_sym_LT] = 1034,
        [anon_sym_LT_EQ] = 1034,
        [anon_sym_GT] = 1034,
        [anon_sym_GT_EQ] = 1034,
        [anon_sym_AMP_AMP] = 1036,
        [anon_sym_PIPE_PIPE] = 1038,
        [sym_comment] = 8,
    },
    [420] = {
        [aux_sym_expression_list_repeat1] = 482,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 482,
        [anon_sym_LPAREN] = 482,
        [anon_sym_COMMA] = 482,
        [anon_sym_STAR] = 482,
        [anon_sym_SLASH] = 482,
        [anon_sym_PERCENT] = 482,
        [anon_sym_LT_LT] = 482,
        [anon_sym_GT_GT] = 482,
        [anon_sym_AMP] = 482,
        [anon_sym_AMP_CARET] = 482,
        [anon_sym_PLUS] = 482,
        [anon_sym_DASH] = 482,
        [anon_sym_PIPE] = 482,
        [anon_sym_CARET] = 482,
        [anon_sym_EQ_EQ] = 482,
        [anon_sym_BANG_EQ] = 482,
        [anon_sym_LT] = 482,
        [anon_sym_LT_EQ] = 482,
        [anon_sym_GT] = 482,
        [anon_sym_GT_EQ] = 482,
        [anon_sym_AMP_AMP] = 482,
        [anon_sym_PIPE_PIPE] = 482,
        [sym_comment] = 8,
    },
    [421] = {
        [aux_sym_expression_list_repeat1] = 484,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 484,
        [anon_sym_LPAREN] = 484,
        [anon_sym_COMMA] = 484,
        [anon_sym_STAR] = 484,
        [anon_sym_SLASH] = 484,
        [anon_sym_PERCENT] = 484,
        [anon_sym_LT_LT] = 484,
        [anon_sym_GT_GT] = 484,
        [anon_sym_AMP] = 484,
        [anon_sym_AMP_CARET] = 484,
        [anon_sym_PLUS] = 484,
        [anon_sym_DASH] = 484,
        [anon_sym_PIPE] = 484,
        [anon_sym_CARET] = 484,
        [anon_sym_EQ_EQ] = 484,
        [anon_sym_BANG_EQ] = 484,
        [anon_sym_LT] = 484,
        [anon_sym_LT_EQ] = 484,
        [anon_sym_GT] = 484,
        [anon_sym_GT_EQ] = 484,
        [anon_sym_AMP_AMP] = 484,
        [anon_sym_PIPE_PIPE] = 484,
        [sym_comment] = 8,
    },
    [422] = {
        [aux_sym_expression_list_repeat1] = 400,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 400,
        [anon_sym_LPAREN] = 400,
        [anon_sym_COMMA] = 400,
        [anon_sym_STAR] = 400,
        [anon_sym_SLASH] = 400,
        [anon_sym_PERCENT] = 400,
        [anon_sym_LT_LT] = 400,
        [anon_sym_GT_GT] = 400,
        [anon_sym_AMP] = 400,
        [anon_sym_AMP_CARET] = 400,
        [anon_sym_PLUS] = 400,
        [anon_sym_DASH] = 400,
        [anon_sym_PIPE] = 400,
        [anon_sym_CARET] = 400,
        [anon_sym_EQ_EQ] = 400,
        [anon_sym_BANG_EQ] = 400,
        [anon_sym_LT] = 400,
        [anon_sym_LT_EQ] = 400,
        [anon_sym_GT] = 400,
        [anon_sym_GT_EQ] = 400,
        [anon_sym_AMP_AMP] = 400,
        [anon_sym_PIPE_PIPE] = 400,
        [sym_comment] = 8,
    },
    [423] = {
        [aux_sym_expression_list_repeat1] = 488,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 488,
        [anon_sym_LPAREN] = 488,
        [anon_sym_COMMA] = 488,
        [anon_sym_STAR] = 488,
        [anon_sym_SLASH] = 488,
        [anon_sym_PERCENT] = 488,
        [anon_sym_LT_LT] = 488,
        [anon_sym_GT_GT] = 488,
        [anon_sym_AMP] = 488,
        [anon_sym_AMP_CARET] = 488,
        [anon_sym_PLUS] = 488,
        [anon_sym_DASH] = 488,
        [anon_sym_PIPE] = 488,
        [anon_sym_CARET] = 488,
        [anon_sym_EQ_EQ] = 488,
        [anon_sym_BANG_EQ] = 488,
        [anon_sym_LT] = 488,
        [anon_sym_LT_EQ] = 488,
        [anon_sym_GT] = 488,
        [anon_sym_GT_EQ] = 488,
        [anon_sym_AMP_AMP] = 488,
        [anon_sym_PIPE_PIPE] = 488,
        [sym_comment] = 8,
    },
    [424] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 542,
        [sym_comment] = 8,
    },
    [425] = {
        [sym_expression_list] = 1040,
        [sym__expression] = 494,
        [sym_call_expression] = 496,
        [sym_unary_expression] = 496,
        [sym_binary_expression] = 496,
        [sym__primary_expression] = 496,
        [sym__string_literal] = 498,
        [sym_int_literal] = 498,
        [sym_float_literal] = 498,
        [sym_identifier] = 498,
        [sym_raw_string_literal] = 500,
        [sym_interpreted_string_literal] = 500,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 502,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 502,
        [sym_comment] = 8,
    },
    [426] = {
        [sym__expression] = 1042,
        [sym_call_expression] = 944,
        [sym_unary_expression] = 944,
        [sym_binary_expression] = 944,
        [sym__primary_expression] = 944,
        [sym__string_literal] = 946,
        [sym_int_literal] = 946,
        [sym_float_literal] = 946,
        [sym_identifier] = 946,
        [sym_raw_string_literal] = 948,
        [sym_interpreted_string_literal] = 948,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 950,
        [sym_comment] = 8,
    },
    [427] = {
        [sym__expression] = 1044,
        [sym_call_expression] = 944,
        [sym_unary_expression] = 944,
        [sym_binary_expression] = 944,
        [sym__primary_expression] = 944,
        [sym__string_literal] = 946,
        [sym_int_literal] = 946,
        [sym_float_literal] = 946,
        [sym_identifier] = 946,
        [sym_raw_string_literal] = 948,
        [sym_interpreted_string_literal] = 948,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 950,
        [sym_comment] = 8,
    },
    [428] = {
        [sym__expression] = 1046,
        [sym_call_expression] = 944,
        [sym_unary_expression] = 944,
        [sym_binary_expression] = 944,
        [sym__primary_expression] = 944,
        [sym__string_literal] = 946,
        [sym_int_literal] = 946,
        [sym_float_literal] = 946,
        [sym_identifier] = 946,
        [sym_raw_string_literal] = 948,
        [sym_interpreted_string_literal] = 948,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 950,
        [sym_comment] = 8,
    },
    [429] = {
        [sym__expression] = 1048,
        [sym_call_expression] = 944,
        [sym_unary_expression] = 944,
        [sym_binary_expression] = 944,
        [sym__primary_expression] = 944,
        [sym__string_literal] = 946,
        [sym_int_literal] = 946,
        [sym_float_literal] = 946,
        [sym_identifier] = 946,
        [sym_raw_string_literal] = 948,
        [sym_interpreted_string_literal] = 948,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 950,
        [sym_comment] = 8,
    },
    [430] = {
        [sym__expression] = 1050,
        [sym_call_expression] = 944,
        [sym_unary_expression] = 944,
        [sym_binary_expression] = 944,
        [sym__primary_expression] = 944,
        [sym__string_literal] = 946,
        [sym_int_literal] = 946,
        [sym_float_literal] = 946,
        [sym_identifier] = 946,
        [sym_raw_string_literal] = 948,
        [sym_interpreted_string_literal] = 948,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 950,
        [sym_comment] = 8,
    },
    [431] = {
        [sym__expression] = 1052,
        [sym_call_expression] = 944,
        [sym_unary_expression] = 944,
        [sym_binary_expression] = 944,
        [sym__primary_expression] = 944,
        [sym__string_literal] = 946,
        [sym_int_literal] = 946,
        [sym_float_literal] = 946,
        [sym_identifier] = 946,
        [sym_raw_string_literal] = 948,
        [sym_interpreted_string_literal] = 948,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 950,
        [sym_comment] = 8,
    },
    [432] = {
        [aux_sym_expression_list_repeat1] = 516,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 516,
        [anon_sym_LPAREN] = 516,
        [anon_sym_COMMA] = 516,
        [anon_sym_STAR] = 1030,
        [anon_sym_SLASH] = 1030,
        [anon_sym_PERCENT] = 1030,
        [anon_sym_LT_LT] = 1030,
        [anon_sym_GT_GT] = 1030,
        [anon_sym_AMP] = 1030,
        [anon_sym_AMP_CARET] = 1030,
        [anon_sym_PLUS] = 1032,
        [anon_sym_DASH] = 1032,
        [anon_sym_PIPE] = 1032,
        [anon_sym_CARET] = 1032,
        [anon_sym_EQ_EQ] = 1034,
        [anon_sym_BANG_EQ] = 1034,
        [anon_sym_LT] = 1034,
        [anon_sym_LT_EQ] = 1034,
        [anon_sym_GT] = 1034,
        [anon_sym_GT_EQ] = 1034,
        [anon_sym_AMP_AMP] = 1036,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [433] = {
        [aux_sym_expression_list_repeat1] = 516,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 516,
        [anon_sym_LPAREN] = 516,
        [anon_sym_COMMA] = 516,
        [anon_sym_STAR] = 1030,
        [anon_sym_SLASH] = 1030,
        [anon_sym_PERCENT] = 1030,
        [anon_sym_LT_LT] = 1030,
        [anon_sym_GT_GT] = 1030,
        [anon_sym_AMP] = 1030,
        [anon_sym_AMP_CARET] = 1030,
        [anon_sym_PLUS] = 1032,
        [anon_sym_DASH] = 1032,
        [anon_sym_PIPE] = 1032,
        [anon_sym_CARET] = 1032,
        [anon_sym_EQ_EQ] = 1034,
        [anon_sym_BANG_EQ] = 1034,
        [anon_sym_LT] = 1034,
        [anon_sym_LT_EQ] = 1034,
        [anon_sym_GT] = 1034,
        [anon_sym_GT_EQ] = 1034,
        [anon_sym_AMP_AMP] = 516,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [434] = {
        [aux_sym_expression_list_repeat1] = 516,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 516,
        [anon_sym_LPAREN] = 516,
        [anon_sym_COMMA] = 516,
        [anon_sym_STAR] = 1030,
        [anon_sym_SLASH] = 1030,
        [anon_sym_PERCENT] = 1030,
        [anon_sym_LT_LT] = 1030,
        [anon_sym_GT_GT] = 1030,
        [anon_sym_AMP] = 1030,
        [anon_sym_AMP_CARET] = 1030,
        [anon_sym_PLUS] = 1032,
        [anon_sym_DASH] = 1032,
        [anon_sym_PIPE] = 1032,
        [anon_sym_CARET] = 1032,
        [anon_sym_EQ_EQ] = 516,
        [anon_sym_BANG_EQ] = 516,
        [anon_sym_LT] = 516,
        [anon_sym_LT_EQ] = 516,
        [anon_sym_GT] = 516,
        [anon_sym_GT_EQ] = 516,
        [anon_sym_AMP_AMP] = 516,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [435] = {
        [aux_sym_expression_list_repeat1] = 516,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 516,
        [anon_sym_LPAREN] = 516,
        [anon_sym_COMMA] = 516,
        [anon_sym_STAR] = 1030,
        [anon_sym_SLASH] = 1030,
        [anon_sym_PERCENT] = 1030,
        [anon_sym_LT_LT] = 1030,
        [anon_sym_GT_GT] = 1030,
        [anon_sym_AMP] = 1030,
        [anon_sym_AMP_CARET] = 1030,
        [anon_sym_PLUS] = 516,
        [anon_sym_DASH] = 516,
        [anon_sym_PIPE] = 516,
        [anon_sym_CARET] = 516,
        [anon_sym_EQ_EQ] = 516,
        [anon_sym_BANG_EQ] = 516,
        [anon_sym_LT] = 516,
        [anon_sym_LT_EQ] = 516,
        [anon_sym_GT] = 516,
        [anon_sym_GT_EQ] = 516,
        [anon_sym_AMP_AMP] = 516,
        [anon_sym_PIPE_PIPE] = 516,
        [sym_comment] = 8,
    },
    [436] = {
        [aux_sym_expression_list_repeat1] = 518,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 518,
        [anon_sym_LPAREN] = 518,
        [anon_sym_COMMA] = 518,
        [anon_sym_STAR] = 518,
        [anon_sym_SLASH] = 518,
        [anon_sym_PERCENT] = 518,
        [anon_sym_LT_LT] = 518,
        [anon_sym_GT_GT] = 518,
        [anon_sym_AMP] = 518,
        [anon_sym_AMP_CARET] = 518,
        [anon_sym_PLUS] = 518,
        [anon_sym_DASH] = 518,
        [anon_sym_PIPE] = 518,
        [anon_sym_CARET] = 518,
        [anon_sym_EQ_EQ] = 518,
        [anon_sym_BANG_EQ] = 518,
        [anon_sym_LT] = 518,
        [anon_sym_LT_EQ] = 518,
        [anon_sym_GT] = 518,
        [anon_sym_GT_EQ] = 518,
        [anon_sym_AMP_AMP] = 518,
        [anon_sym_PIPE_PIPE] = 518,
        [sym_comment] = 8,
    },
    [437] = {
        [aux_sym_expression_list_repeat1] = 1054,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 560,
        [anon_sym_LPAREN] = 1026,
        [anon_sym_COMMA] = 1028,
        [anon_sym_STAR] = 1030,
        [anon_sym_SLASH] = 1030,
        [anon_sym_PERCENT] = 1030,
        [anon_sym_LT_LT] = 1030,
        [anon_sym_GT_GT] = 1030,
        [anon_sym_AMP] = 1030,
        [anon_sym_AMP_CARET] = 1030,
        [anon_sym_PLUS] = 1032,
        [anon_sym_DASH] = 1032,
        [anon_sym_PIPE] = 1032,
        [anon_sym_CARET] = 1032,
        [anon_sym_EQ_EQ] = 1034,
        [anon_sym_BANG_EQ] = 1034,
        [anon_sym_LT] = 1034,
        [anon_sym_LT_EQ] = 1034,
        [anon_sym_GT] = 1034,
        [anon_sym_GT_EQ] = 1034,
        [anon_sym_AMP_AMP] = 1036,
        [anon_sym_PIPE_PIPE] = 1038,
        [sym_comment] = 8,
    },
    [438] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 562,
        [sym_comment] = 8,
    },
    [439] = {
        [anon_sym_RPAREN] = 1056,
        [sym_comment] = 8,
    },
    [440] = {
        [aux_sym_expression_list_repeat1] = 566,
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 566,
        [anon_sym_LPAREN] = 566,
        [anon_sym_COMMA] = 566,
        [anon_sym_STAR] = 566,
        [anon_sym_SLASH] = 566,
        [anon_sym_PERCENT] = 566,
        [anon_sym_LT_LT] = 566,
        [anon_sym_GT_GT] = 566,
        [anon_sym_AMP] = 566,
        [anon_sym_AMP_CARET] = 566,
        [anon_sym_PLUS] = 566,
        [anon_sym_DASH] = 566,
        [anon_sym_PIPE] = 566,
        [anon_sym_CARET] = 566,
        [anon_sym_EQ_EQ] = 566,
        [anon_sym_BANG_EQ] = 566,
        [anon_sym_LT] = 566,
        [anon_sym_LT_EQ] = 566,
        [anon_sym_GT] = 566,
        [anon_sym_GT_EQ] = 566,
        [anon_sym_AMP_AMP] = 566,
        [anon_sym_PIPE_PIPE] = 566,
        [sym_comment] = 8,
    },
    [441] = {
        [sym_expression_list] = 1058,
        [sym__expression] = 942,
        [sym_call_expression] = 944,
        [sym_unary_expression] = 944,
        [sym_binary_expression] = 944,
        [sym__primary_expression] = 944,
        [sym__string_literal] = 946,
        [sym_int_literal] = 946,
        [sym_float_literal] = 946,
        [sym_identifier] = 946,
        [sym_raw_string_literal] = 948,
        [sym_interpreted_string_literal] = 948,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 950,
        [sym_comment] = 8,
    },
    [442] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 1060,
        [sym_comment] = 8,
    },
    [443] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 1062,
        [sym_comment] = 8,
    },
    [444] = {
        [sym__type] = 1064,
        [sym_pointer_type] = 1066,
        [sym_array_type] = 1066,
        [sym_slice_type] = 1066,
        [sym_struct_type] = 1066,
        [sym_interface_type] = 1066,
        [sym_map_type] = 1066,
        [sym_channel_type] = 1066,
        [sym_function_type] = 1066,
        [sym_qualified_identifier] = 1066,
        [anon_sym_EQ] = 1068,
        [anon_sym_func] = 1070,
        [anon_sym_STAR] = 1072,
        [anon_sym_LBRACK] = 1074,
        [anon_sym_struct] = 1076,
        [anon_sym_interface] = 1078,
        [anon_sym_map] = 1080,
        [anon_sym_chan] = 1082,
        [anon_sym_LT_DASH] = 1084,
        [sym_identifier] = 1086,
        [sym_comment] = 8,
    },
    [445] = {
        [sym_const_spec] = 1088,
        [sym_identifier_list] = 66,
        [aux_sym_const_declaration_repeat1] = 1090,
        [anon_sym_RPAREN] = 1092,
        [sym_identifier] = 70,
        [sym_comment] = 8,
    },
    [446] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 1094,
        [sym_comment] = 8,
    },
    [447] = {
        [anon_sym_RPAREN] = 1096,
        [sym_comment] = 8,
    },
    [448] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 1098,
        [sym_comment] = 8,
    },
    [449] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 1100,
        [sym_comment] = 8,
    },
    [450] = {
        [sym_const_spec] = 1088,
        [sym_identifier_list] = 66,
        [aux_sym_const_declaration_repeat1] = 1102,
        [anon_sym_RPAREN] = 1104,
        [sym_identifier] = 70,
        [sym_comment] = 8,
    },
    [451] = {
        [anon_sym_RPAREN] = 1106,
        [sym_comment] = 8,
    },
    [452] = {
        [anon_sym_EQ] = 1108,
        [sym_comment] = 8,
    },
    [453] = {
        [anon_sym_EQ] = 122,
        [sym_comment] = 8,
    },
    [454] = {
        [sym_expression_list] = 1110,
        [sym__expression] = 942,
        [sym_call_expression] = 944,
        [sym_unary_expression] = 944,
        [sym_binary_expression] = 944,
        [sym__primary_expression] = 944,
        [sym__string_literal] = 946,
        [sym_int_literal] = 946,
        [sym_float_literal] = 946,
        [sym_identifier] = 946,
        [sym_raw_string_literal] = 948,
        [sym_interpreted_string_literal] = 948,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 950,
        [sym_comment] = 8,
    },
    [455] = {
        [sym_parameters] = 1112,
        [anon_sym_LPAREN] = 1114,
        [sym_comment] = 8,
    },
    [456] = {
        [sym__type] = 1116,
        [sym_pointer_type] = 1066,
        [sym_array_type] = 1066,
        [sym_slice_type] = 1066,
        [sym_struct_type] = 1066,
        [sym_interface_type] = 1066,
        [sym_map_type] = 1066,
        [sym_channel_type] = 1066,
        [sym_function_type] = 1066,
        [sym_qualified_identifier] = 1066,
        [anon_sym_func] = 1070,
        [anon_sym_STAR] = 1072,
        [anon_sym_LBRACK] = 1074,
        [anon_sym_struct] = 1076,
        [anon_sym_interface] = 1078,
        [anon_sym_map] = 1080,
        [anon_sym_chan] = 1082,
        [anon_sym_LT_DASH] = 1084,
        [sym_identifier] = 1086,
        [sym_comment] = 8,
    },
    [457] = {
        [sym__expression] = 1118,
        [sym_call_expression] = 132,
        [sym_unary_expression] = 132,
        [sym_binary_expression] = 132,
        [sym__primary_expression] = 132,
        [sym__string_literal] = 134,
        [sym_int_literal] = 134,
        [sym_float_literal] = 134,
        [anon_sym_RBRACK] = 1120,
        [sym_identifier] = 134,
        [sym_raw_string_literal] = 138,
        [sym_interpreted_string_literal] = 138,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 140,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 140,
        [sym_comment] = 8,
    },
    [458] = {
        [anon_sym_LBRACE] = 1122,
        [sym_comment] = 8,
    },
    [459] = {
        [anon_sym_LBRACE] = 1124,
        [sym_comment] = 8,
    },
    [460] = {
        [anon_sym_LBRACK] = 1126,
        [sym_comment] = 8,
    },
    [461] = {
        [sym__type] = 1128,
        [sym_pointer_type] = 1066,
        [sym_array_type] = 1066,
        [sym_slice_type] = 1066,
        [sym_struct_type] = 1066,
        [sym_interface_type] = 1066,
        [sym_map_type] = 1066,
        [sym_channel_type] = 1066,
        [sym_function_type] = 1066,
        [sym_qualified_identifier] = 1066,
        [anon_sym_func] = 1070,
        [anon_sym_STAR] = 1072,
        [anon_sym_LBRACK] = 1074,
        [anon_sym_struct] = 1076,
        [anon_sym_interface] = 1078,
        [anon_sym_map] = 1080,
        [anon_sym_chan] = 1082,
        [anon_sym_LT_DASH] = 1130,
        [sym_identifier] = 1086,
        [sym_comment] = 8,
    },
    [462] = {
        [anon_sym_chan] = 1132,
        [sym_comment] = 8,
    },
    [463] = {
        [anon_sym_DOT] = 1134,
        [anon_sym_EQ] = 122,
        [sym_comment] = 8,
    },
    [464] = {
        [sym_identifier] = 1136,
        [sym_comment] = 8,
    },
    [465] = {
        [anon_sym_EQ] = 158,
        [sym_comment] = 8,
    },
    [466] = {
        [sym__type] = 1138,
        [sym_pointer_type] = 1066,
        [sym_array_type] = 1066,
        [sym_slice_type] = 1066,
        [sym_struct_type] = 1066,
        [sym_interface_type] = 1066,
        [sym_map_type] = 1066,
        [sym_channel_type] = 1066,
        [sym_function_type] = 1066,
        [sym_qualified_identifier] = 1066,
        [anon_sym_func] = 1070,
        [anon_sym_STAR] = 1072,
        [anon_sym_LBRACK] = 1074,
        [anon_sym_struct] = 1076,
        [anon_sym_interface] = 1078,
        [anon_sym_map] = 1080,
        [anon_sym_chan] = 1082,
        [anon_sym_LT_DASH] = 1084,
        [sym_identifier] = 1086,
        [sym_comment] = 8,
    },
    [467] = {
        [anon_sym_EQ] = 162,
        [sym_comment] = 8,
    },
    [468] = {
        [anon_sym_EQ] = 164,
        [sym_comment] = 8,
    },
    [469] = {
        [sym__type] = 1140,
        [sym_pointer_type] = 1066,
        [sym_array_type] = 1066,
        [sym_slice_type] = 1066,
        [sym_struct_type] = 1066,
        [sym_interface_type] = 1066,
        [sym_map_type] = 1066,
        [sym_channel_type] = 1066,
        [sym_function_type] = 1066,
        [sym_qualified_identifier] = 1066,
        [anon_sym_func] = 1070,
        [anon_sym_STAR] = 1072,
        [anon_sym_LBRACK] = 1074,
        [anon_sym_struct] = 1076,
        [anon_sym_interface] = 1078,
        [anon_sym_map] = 1080,
        [anon_sym_chan] = 1082,
        [anon_sym_LT_DASH] = 1084,
        [sym_identifier] = 1086,
        [sym_comment] = 8,
    },
    [470] = {
        [anon_sym_EQ] = 168,
        [sym_comment] = 8,
    },
    [471] = {
        [sym__type] = 1142,
        [sym_pointer_type] = 172,
        [sym_array_type] = 172,
        [sym_slice_type] = 172,
        [sym_struct_type] = 172,
        [sym_interface_type] = 172,
        [sym_map_type] = 172,
        [sym_channel_type] = 172,
        [sym_function_type] = 172,
        [sym_qualified_identifier] = 172,
        [anon_sym_func] = 174,
        [anon_sym_STAR] = 176,
        [anon_sym_LBRACK] = 178,
        [anon_sym_struct] = 180,
        [anon_sym_interface] = 182,
        [anon_sym_map] = 184,
        [anon_sym_chan] = 186,
        [anon_sym_LT_DASH] = 188,
        [sym_identifier] = 190,
        [sym_comment] = 8,
    },
    [472] = {
        [anon_sym_RBRACK] = 1144,
        [sym_comment] = 8,
    },
    [473] = {
        [sym__type] = 1146,
        [sym_pointer_type] = 1066,
        [sym_array_type] = 1066,
        [sym_slice_type] = 1066,
        [sym_struct_type] = 1066,
        [sym_interface_type] = 1066,
        [sym_map_type] = 1066,
        [sym_channel_type] = 1066,
        [sym_function_type] = 1066,
        [sym_qualified_identifier] = 1066,
        [anon_sym_func] = 1070,
        [anon_sym_STAR] = 1072,
        [anon_sym_LBRACK] = 1074,
        [anon_sym_struct] = 1076,
        [anon_sym_interface] = 1078,
        [anon_sym_map] = 1080,
        [anon_sym_chan] = 1082,
        [anon_sym_LT_DASH] = 1084,
        [sym_identifier] = 1086,
        [sym_comment] = 8,
    },
    [474] = {
        [anon_sym_EQ] = 230,
        [sym_comment] = 8,
    },
    [475] = {
        [sym_method_spec] = 232,
        [aux_sym_interface_type_repeat1] = 1148,
        [anon_sym_RBRACE] = 1150,
        [sym_identifier] = 238,
        [sym_comment] = 8,
    },
    [476] = {
        [anon_sym_RBRACE] = 1152,
        [sym_comment] = 8,
    },
    [477] = {
        [anon_sym_EQ] = 244,
        [sym_comment] = 8,
    },
    [478] = {
        [anon_sym_EQ] = 340,
        [sym_comment] = 8,
    },
    [479] = {
        [sym_identifier_list] = 342,
        [sym_field_declaration] = 344,
        [aux_sym_struct_type_repeat1] = 1154,
        [anon_sym_STAR] = 348,
        [anon_sym_RBRACE] = 1156,
        [sym_identifier] = 352,
        [sym_comment] = 8,
    },
    [480] = {
        [anon_sym_RBRACE] = 1158,
        [sym_comment] = 8,
    },
    [481] = {
        [anon_sym_EQ] = 380,
        [sym_comment] = 8,
    },
    [482] = {
        [anon_sym_EQ] = 412,
        [sym_comment] = 8,
    },
    [483] = {
        [anon_sym_LPAREN] = 468,
        [anon_sym_STAR] = 470,
        [anon_sym_RBRACK] = 1160,
        [anon_sym_SLASH] = 470,
        [anon_sym_PERCENT] = 470,
        [anon_sym_LT_LT] = 470,
        [anon_sym_GT_GT] = 470,
        [anon_sym_AMP] = 470,
        [anon_sym_AMP_CARET] = 470,
        [anon_sym_PLUS] = 474,
        [anon_sym_DASH] = 474,
        [anon_sym_PIPE] = 474,
        [anon_sym_CARET] = 474,
        [anon_sym_EQ_EQ] = 476,
        [anon_sym_BANG_EQ] = 476,
        [anon_sym_LT] = 476,
        [anon_sym_LT_EQ] = 476,
        [anon_sym_GT] = 476,
        [anon_sym_GT_EQ] = 476,
        [anon_sym_AMP_AMP] = 478,
        [anon_sym_PIPE_PIPE] = 480,
        [sym_comment] = 8,
    },
    [484] = {
        [sym__type] = 1162,
        [sym_pointer_type] = 1066,
        [sym_array_type] = 1066,
        [sym_slice_type] = 1066,
        [sym_struct_type] = 1066,
        [sym_interface_type] = 1066,
        [sym_map_type] = 1066,
        [sym_channel_type] = 1066,
        [sym_function_type] = 1066,
        [sym_qualified_identifier] = 1066,
        [anon_sym_func] = 1070,
        [anon_sym_STAR] = 1072,
        [anon_sym_LBRACK] = 1074,
        [anon_sym_struct] = 1076,
        [anon_sym_interface] = 1078,
        [anon_sym_map] = 1080,
        [anon_sym_chan] = 1082,
        [anon_sym_LT_DASH] = 1084,
        [sym_identifier] = 1086,
        [sym_comment] = 8,
    },
    [485] = {
        [anon_sym_EQ] = 490,
        [sym_comment] = 8,
    },
    [486] = {
        [sym__type] = 1164,
        [sym_pointer_type] = 1066,
        [sym_array_type] = 1066,
        [sym_slice_type] = 1066,
        [sym_struct_type] = 1066,
        [sym_interface_type] = 1066,
        [sym_map_type] = 1066,
        [sym_channel_type] = 1066,
        [sym_function_type] = 1066,
        [sym_qualified_identifier] = 1066,
        [anon_sym_func] = 1070,
        [anon_sym_STAR] = 1072,
        [anon_sym_LBRACK] = 1074,
        [anon_sym_struct] = 1076,
        [anon_sym_interface] = 1078,
        [anon_sym_map] = 1080,
        [anon_sym_chan] = 1082,
        [anon_sym_LT_DASH] = 1084,
        [sym_identifier] = 1086,
        [sym_comment] = 8,
    },
    [487] = {
        [anon_sym_EQ] = 520,
        [sym_comment] = 8,
    },
    [488] = {
        [anon_sym_EQ] = 568,
        [sym_comment] = 8,
    },
    [489] = {
        [sym_parameters] = 1166,
        [sym__type] = 1166,
        [sym_pointer_type] = 1066,
        [sym_array_type] = 1066,
        [sym_slice_type] = 1066,
        [sym_struct_type] = 1066,
        [sym_interface_type] = 1066,
        [sym_map_type] = 1066,
        [sym_channel_type] = 1066,
        [sym_function_type] = 1066,
        [sym_qualified_identifier] = 1066,
        [anon_sym_LPAREN] = 1168,
        [anon_sym_EQ] = 572,
        [anon_sym_func] = 1070,
        [anon_sym_STAR] = 1072,
        [anon_sym_LBRACK] = 1074,
        [anon_sym_struct] = 1076,
        [anon_sym_interface] = 1078,
        [anon_sym_map] = 1080,
        [anon_sym_chan] = 1082,
        [anon_sym_LT_DASH] = 1084,
        [sym_identifier] = 1086,
        [sym_comment] = 8,
    },
    [490] = {
        [sym__parameter_list] = 1170,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 1172,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [491] = {
        [anon_sym_RPAREN] = 1174,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [492] = {
        [sym_parameters] = 272,
        [sym__type] = 272,
        [sym_pointer_type] = 272,
        [sym_array_type] = 272,
        [sym_slice_type] = 272,
        [sym_struct_type] = 272,
        [sym_interface_type] = 272,
        [sym_map_type] = 272,
        [sym_channel_type] = 272,
        [sym_function_type] = 272,
        [sym_qualified_identifier] = 272,
        [anon_sym_LPAREN] = 272,
        [anon_sym_EQ] = 272,
        [anon_sym_func] = 272,
        [anon_sym_STAR] = 272,
        [anon_sym_LBRACK] = 272,
        [anon_sym_struct] = 272,
        [anon_sym_interface] = 272,
        [anon_sym_map] = 272,
        [anon_sym_chan] = 272,
        [anon_sym_LT_DASH] = 272,
        [sym_identifier] = 272,
        [sym_comment] = 8,
    },
    [493] = {
        [sym_parameters] = 582,
        [sym__type] = 582,
        [sym_pointer_type] = 582,
        [sym_array_type] = 582,
        [sym_slice_type] = 582,
        [sym_struct_type] = 582,
        [sym_interface_type] = 582,
        [sym_map_type] = 582,
        [sym_channel_type] = 582,
        [sym_function_type] = 582,
        [sym_qualified_identifier] = 582,
        [anon_sym_LPAREN] = 582,
        [anon_sym_EQ] = 582,
        [anon_sym_func] = 582,
        [anon_sym_STAR] = 582,
        [anon_sym_LBRACK] = 582,
        [anon_sym_struct] = 582,
        [anon_sym_interface] = 582,
        [anon_sym_map] = 582,
        [anon_sym_chan] = 582,
        [anon_sym_LT_DASH] = 582,
        [sym_identifier] = 582,
        [sym_comment] = 8,
    },
    [494] = {
        [anon_sym_EQ] = 590,
        [sym_comment] = 8,
    },
    [495] = {
        [sym__parameter_list] = 1176,
        [sym_parameter_declaration] = 260,
        [anon_sym_RPAREN] = 1178,
        [sym_identifier] = 264,
        [sym_comment] = 8,
    },
    [496] = {
        [anon_sym_RPAREN] = 1180,
        [anon_sym_COMMA] = 268,
        [sym_comment] = 8,
    },
    [497] = {
        [anon_sym_EQ] = 272,
        [sym_comment] = 8,
    },
    [498] = {
        [anon_sym_EQ] = 582,
        [sym_comment] = 8,
    },
    [499] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 1182,
        [sym_comment] = 8,
    },
    [500] = {
        [sym_expression_list] = 1184,
        [sym__expression] = 942,
        [sym_call_expression] = 944,
        [sym_unary_expression] = 944,
        [sym_binary_expression] = 944,
        [sym__primary_expression] = 944,
        [sym__string_literal] = 946,
        [sym_int_literal] = 946,
        [sym_float_literal] = 946,
        [sym_identifier] = 946,
        [sym_raw_string_literal] = 948,
        [sym_interpreted_string_literal] = 948,
        [aux_sym_SLASH_LBRACK1_DASH9_RBRACK_LPAREN_LBRACK0_DASH9_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPAREN_LBRACK0_DASH7_RBRACK_STAR_PIPE_RPAREN_SLASH] = 950,
        [aux_sym_SLASH0_LPARENx_PIPEX_RPAREN_LBRACK0_DASH7_RBRACK_STAR_SLASH] = 950,
        [sym_comment] = 8,
    },
    [501] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 1186,
        [sym_comment] = 8,
    },
    [502] = {
        [sym_import_declaration] = 1188,
        [sym__top_level_declaration] = 1188,
        [sym__declaration] = 1188,
        [sym_const_declaration] = 1188,
        [sym_var_declaration] = 1188,
        [sym_function_declaration] = 1188,
        [sym_method_declaration] = 1188,
        [sym_type_declaration] = 1188,
        [aux_sym_source_file_repeat1] = 1188,
        [aux_sym_source_file_repeat2] = 1188,
        [ts_builtin_sym_end] = 1188,
        [anon_sym_import] = 1188,
        [anon_sym_const] = 1188,
        [anon_sym_var] = 1188,
        [anon_sym_func] = 1188,
        [anon_sym_type] = 1188,
        [sym_comment] = 8,
    },
    [503] = {
        [sym_import_declaration] = 1190,
        [sym__top_level_declaration] = 1190,
        [sym__declaration] = 1190,
        [sym_const_declaration] = 1190,
        [sym_var_declaration] = 1190,
        [sym_function_declaration] = 1190,
        [sym_method_declaration] = 1190,
        [sym_type_declaration] = 1190,
        [aux_sym_source_file_repeat1] = 1190,
        [aux_sym_source_file_repeat2] = 1190,
        [ts_builtin_sym_end] = 1190,
        [anon_sym_import] = 1190,
        [anon_sym_const] = 1190,
        [anon_sym_var] = 1190,
        [anon_sym_func] = 1190,
        [anon_sym_type] = 1190,
        [sym_comment] = 8,
    },
    [504] = {
        [sym_import_spec] = 1192,
        [sym__string_literal] = 1194,
        [aux_sym_import_declaration_repeat1] = 1196,
        [anon_sym_RPAREN] = 1198,
        [anon_sym_DOT] = 1200,
        [sym_identifier] = 1200,
        [sym_raw_string_literal] = 392,
        [sym_interpreted_string_literal] = 392,
        [sym_comment] = 8,
    },
    [505] = {
        [sym__string_literal] = 1202,
        [sym_raw_string_literal] = 62,
        [sym_interpreted_string_literal] = 62,
        [sym_comment] = 8,
    },
    [506] = {
        [sym_import_declaration] = 400,
        [sym__top_level_declaration] = 400,
        [sym__declaration] = 400,
        [sym_const_declaration] = 400,
        [sym_var_declaration] = 400,
        [sym_function_declaration] = 400,
        [sym_method_declaration] = 400,
        [sym_type_declaration] = 400,
        [aux_sym_source_file_repeat1] = 400,
        [aux_sym_source_file_repeat2] = 400,
        [ts_builtin_sym_end] = 400,
        [anon_sym_import] = 400,
        [anon_sym_const] = 400,
        [anon_sym_var] = 400,
        [anon_sym_func] = 400,
        [anon_sym_type] = 400,
        [sym_comment] = 8,
    },
    [507] = {
        [sym_import_declaration] = 1204,
        [sym__top_level_declaration] = 1204,
        [sym__declaration] = 1204,
        [sym_const_declaration] = 1204,
        [sym_var_declaration] = 1204,
        [sym_function_declaration] = 1204,
        [sym_method_declaration] = 1204,
        [sym_type_declaration] = 1204,
        [aux_sym_source_file_repeat1] = 1204,
        [aux_sym_source_file_repeat2] = 1204,
        [ts_builtin_sym_end] = 1204,
        [anon_sym_import] = 1204,
        [anon_sym_const] = 1204,
        [anon_sym_var] = 1204,
        [anon_sym_func] = 1204,
        [anon_sym_type] = 1204,
        [sym_comment] = 8,
    },
    [508] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 1206,
        [sym_comment] = 8,
    },
    [509] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 1190,
        [sym_comment] = 8,
    },
    [510] = {
        [anon_sym_RPAREN] = 1208,
        [sym_comment] = 8,
    },
    [511] = {
        [sym_import_declaration] = 1210,
        [sym__top_level_declaration] = 1210,
        [sym__declaration] = 1210,
        [sym_const_declaration] = 1210,
        [sym_var_declaration] = 1210,
        [sym_function_declaration] = 1210,
        [sym_method_declaration] = 1210,
        [sym_type_declaration] = 1210,
        [aux_sym_source_file_repeat1] = 1210,
        [aux_sym_source_file_repeat2] = 1210,
        [ts_builtin_sym_end] = 1210,
        [anon_sym_import] = 1210,
        [anon_sym_const] = 1210,
        [anon_sym_var] = 1210,
        [anon_sym_func] = 1210,
        [anon_sym_type] = 1210,
        [sym_comment] = 8,
    },
    [512] = {
        [sym__string_literal] = 1212,
        [sym_raw_string_literal] = 392,
        [sym_interpreted_string_literal] = 392,
        [sym_comment] = 8,
    },
    [513] = {
        [aux_sym_SLASH_LPAREN_LF_PIPE_SEMI_RPAREN_SLASH] = 1204,
        [sym_comment] = 8,
    },
    [514] = {
        [sym_import_declaration] = 1214,
        [sym__top_level_declaration] = 1214,
        [sym__declaration] = 1214,
        [sym_const_declaration] = 1214,
        [sym_var_declaration] = 1214,
        [sym_function_declaration] = 1214,
        [sym_method_declaration] = 1214,
        [sym_type_declaration] = 1214,
        [aux_sym_source_file_repeat1] = 1214,
        [aux_sym_source_file_repeat2] = 1214,
        [ts_builtin_sym_end] = 1214,
        [anon_sym_import] = 1214,
        [anon_sym_const] = 1214,
        [anon_sym_var] = 1214,
        [anon_sym_func] = 1214,
        [anon_sym_type] = 1214,
        [sym_comment] = 8,
    },
    [515] = {
        [sym_import_spec] = 1192,
        [sym__string_literal] = 1194,
        [aux_sym_import_declaration_repeat1] = 1216,
        [anon_sym_RPAREN] = 1218,
        [anon_sym_DOT] = 1200,
        [sym_identifier] = 1200,
        [sym_raw_string_literal] = 392,
        [sym_interpreted_string_literal] = 392,
        [sym_comment] = 8,
    },
    [516] = {
        [anon_sym_RPAREN] = 1220,
        [sym_comment] = 8,
    },
    [517] = {
        [ts_builtin_sym_end] = 1222,
        [sym_comment] = 8,
    },
    [518] = {
        [sym__top_level_declaration] = 14,
        [sym__declaration] = 16,
        [sym_const_declaration] = 18,
        [sym_var_declaration] = 18,
        [sym_function_declaration] = 16,
        [sym_method_declaration] = 16,
        [sym_type_declaration] = 18,
        [aux_sym_source_file_repeat2] = 1224,
        [ts_builtin_sym_end] = 1226,
        [anon_sym_const] = 28,
        [anon_sym_var] = 30,
        [anon_sym_func] = 32,
        [anon_sym_type] = 34,
        [sym_comment] = 8,
    },
    [519] = {
        [ts_builtin_sym_end] = 1228,
        [sym_comment] = 8,
    },
    [520] = {
        [sym__top_level_declaration] = 1230,
        [sym__declaration] = 1230,
        [sym_const_declaration] = 1230,
        [sym_var_declaration] = 1230,
        [sym_function_declaration] = 1230,
        [sym_method_declaration] = 1230,
        [sym_type_declaration] = 1230,
        [aux_sym_source_file_repeat2] = 1230,
        [ts_builtin_sym_end] = 1230,
        [anon_sym_const] = 1230,
        [anon_sym_var] = 1230,
        [anon_sym_func] = 1230,
        [anon_sym_type] = 1230,
        [sym_comment] = 8,
    },
};

static TSParseActionEntry ts_parse_actions[] = {
    [0] = {.count = 1}, ERROR(),
    [2] = {.count = 1}, SHIFT(1, 0),
    [4] = {.count = 1}, SHIFT(2, 0),
    [6] = {.count = 1}, SHIFT(3, 0),
    [8] = {.count = 1}, SHIFT_EXTRA(),
    [10] = {.count = 1}, ACCEPT_INPUT(),
    [12] = {.count = 1}, SHIFT(5, 0),
    [14] = {.count = 1}, SHIFT(6, 0),
    [16] = {.count = 1}, SHIFT(7, 0),
    [18] = {.count = 1}, SHIFT(8, 0),
    [20] = {.count = 1}, SHIFT(9, 0),
    [22] = {.count = 1}, SHIFT(10, 0),
    [24] = {.count = 1}, REDUCE(sym_source_file, 1, 0),
    [26] = {.count = 1}, SHIFT(11, 0),
    [28] = {.count = 1}, SHIFT(12, 0),
    [30] = {.count = 1}, SHIFT(13, 0),
    [32] = {.count = 1}, SHIFT(14, 0),
    [34] = {.count = 1}, SHIFT(15, 0),
    [36] = {.count = 1}, SHIFT(4, 0),
    [38] = {.count = 1}, REDUCE(sym_package_clause, 2, 0),
    [40] = {.count = 1}, REDUCE(aux_sym_source_file_repeat1, 1, 0),
    [42] = {.count = 1}, SHIFT(520, 0),
    [44] = {.count = 1}, SHIFT(518, 0),
    [46] = {.count = 1}, REDUCE(sym__top_level_declaration, 1, 0),
    [48] = {.count = 1}, REDUCE(sym__declaration, 1, 0),
    [50] = {.count = 1}, SHIFT(517, 0),
    [52] = {.count = 1}, REDUCE(sym_source_file, 2, 0),
    [54] = {.count = 1}, SHIFT(502, 0),
    [56] = {.count = 1}, SHIFT(503, 0),
    [58] = {.count = 1}, SHIFT(504, 0),
    [60] = {.count = 1}, SHIFT(505, 0),
    [62] = {.count = 1}, SHIFT(506, 0),
    [64] = {.count = 1}, SHIFT(443, 0),
    [66] = {.count = 1}, SHIFT(444, 0),
    [68] = {.count = 1}, SHIFT(445, 0),
    [70] = {.count = 1}, SHIFT(360, 0),
    [72] = {.count = 1}, SHIFT(357, 0),
    [74] = {.count = 1}, SHIFT(358, 0),
    [76] = {.count = 1}, SHIFT(359, 0),
    [78] = {.count = 1}, SHIFT(271, 0),
    [80] = {.count = 1}, SHIFT(272, 0),
    [82] = {.count = 1}, SHIFT(273, 0),
    [84] = {.count = 1}, SHIFT(16, 0),
    [86] = {.count = 1}, SHIFT(17, 0),
    [88] = {.count = 1}, SHIFT(18, 0),
    [90] = {.count = 1}, REDUCE(sym_type_declaration, 2, 0),
    [92] = {.count = 1}, SHIFT(265, 0),
    [94] = {.count = 1}, SHIFT(266, 0),
    [96] = {.count = 1}, SHIFT(267, 0),
    [98] = {.count = 1}, SHIFT(19, 0),
    [100] = {.count = 1}, SHIFT(20, 0),
    [102] = {.count = 1}, SHIFT(21, 0),
    [104] = {.count = 1}, SHIFT(22, 0),
    [106] = {.count = 1}, SHIFT(23, 0),
    [108] = {.count = 1}, SHIFT(24, 0),
    [110] = {.count = 1}, SHIFT(25, 0),
    [112] = {.count = 1}, SHIFT(26, 0),
    [114] = {.count = 1}, SHIFT(27, 0),
    [116] = {.count = 1}, SHIFT(28, 0),
    [118] = {.count = 1}, SHIFT(29, 0),
    [120] = {.count = 1}, REDUCE(sym_type_spec, 2, 0),
    [122] = {.count = 1}, REDUCE(sym__type, 1, 0),
    [124] = {.count = 1}, SHIFT(263, 0),
    [126] = {.count = 1}, SHIFT(67, 0),
    [128] = {.count = 1}, SHIFT(262, 0),
    [130] = {.count = 1}, SHIFT(257, 0),
    [132] = {.count = 1}, SHIFT(146, 0),
    [134] = {.count = 1}, SHIFT(147, 0),
    [136] = {.count = 1}, SHIFT(258, 0),
    [138] = {.count = 1}, SHIFT(149, 0),
    [140] = {.count = 1}, SHIFT(150, 0),
    [142] = {.count = 1}, SHIFT(253, 0),
    [144] = {.count = 1}, SHIFT(249, 0),
    [146] = {.count = 1}, SHIFT(37, 0),
    [148] = {.count = 1}, SHIFT(34, 0),
    [150] = {.count = 1}, SHIFT(35, 0),
    [152] = {.count = 1}, SHIFT(32, 0),
    [154] = {.count = 1}, SHIFT(30, 0),
    [156] = {.count = 1}, SHIFT(31, 0),
    [158] = {.count = 1}, REDUCE(sym_qualified_identifier, 3, 0),
    [160] = {.count = 1}, SHIFT(33, 0),
    [162] = {.count = 1}, REDUCE(sym_channel_type, 3, FRAGILE),
    [164] = {.count = 1}, REDUCE(sym_channel_type, 2, 0),
    [166] = {.count = 1}, SHIFT(36, 0),
    [168] = {.count = 1}, REDUCE(sym_channel_type, 3, 0),
    [170] = {.count = 1}, SHIFT(38, 0),
    [172] = {.count = 1}, SHIFT(39, 0),
    [174] = {.count = 1}, SHIFT(40, 0),
    [176] = {.count = 1}, SHIFT(41, 0),
    [178] = {.count = 1}, SHIFT(42, 0),
    [180] = {.count = 1}, SHIFT(43, 0),
    [182] = {.count = 1}, SHIFT(44, 0),
    [184] = {.count = 1}, SHIFT(45, 0),
    [186] = {.count = 1}, SHIFT(46, 0),
    [188] = {.count = 1}, SHIFT(47, 0),
    [190] = {.count = 1}, SHIFT(48, 0),
    [192] = {.count = 1}, SHIFT(247, 0),
    [194] = {.count = 1}, SHIFT(237, 0),
    [196] = {.count = 1}, SHIFT(238, 0),
    [198] = {.count = 1}, SHIFT(236, 0),
    [200] = {.count = 1}, SHIFT(231, 0),
    [202] = {.count = 1}, SHIFT(232, 0),
    [204] = {.count = 1}, SHIFT(227, 0),
    [206] = {.count = 1}, SHIFT(60, 0),
    [208] = {.count = 1}, SHIFT(56, 0),
    [210] = {.count = 1}, SHIFT(53, 0),
    [212] = {.count = 1}, SHIFT(54, 0),
    [214] = {.count = 1}, SHIFT(51, 0),
    [216] = {.count = 1}, SHIFT(49, 0),
    [218] = {.count = 1}, SHIFT(50, 0),
    [220] = {.count = 1}, SHIFT(52, 0),
    [222] = {.count = 1}, SHIFT(55, 0),
    [224] = {.count = 1}, SHIFT(57, 0),
    [226] = {.count = 1}, SHIFT(58, 0),
    [228] = {.count = 1}, SHIFT(59, 0),
    [230] = {.count = 1}, REDUCE(sym_map_type, 5, 0),
    [232] = {.count = 1}, SHIFT(61, 0),
    [234] = {.count = 1}, SHIFT(62, 0),
    [236] = {.count = 1}, SHIFT(63, 0),
    [238] = {.count = 1}, SHIFT(64, 0),
    [240] = {.count = 1}, SHIFT(66, 0),
    [242] = {.count = 1}, SHIFT(226, 0),
    [244] = {.count = 1}, REDUCE(sym_interface_type, 3, 0),
    [246] = {.count = 1}, SHIFT(65, 0),
    [248] = {.count = 1}, SHIFT(221, 0),
    [250] = {.count = 1}, REDUCE(sym_method_spec, 2, 0),
    [252] = {.count = 1}, SHIFT(222, 0),
    [254] = {.count = 1}, SHIFT(220, 0),
    [256] = {.count = 1}, REDUCE(aux_sym_interface_type_repeat1, 2, 0),
    [258] = {.count = 1}, SHIFT(68, 0),
    [260] = {.count = 1}, SHIFT(69, 0),
    [262] = {.count = 1}, SHIFT(70, 0),
    [264] = {.count = 1}, SHIFT(71, 0),
    [266] = {.count = 1}, SHIFT(219, 0),
    [268] = {.count = 1}, SHIFT(195, 0),
    [270] = {.count = 1}, REDUCE(sym__parameter_list, 1, 0),
    [272] = {.count = 1}, REDUCE(sym_parameters, 2, 0),
    [274] = {.count = 1}, SHIFT(72, 0),
    [276] = {.count = 1}, SHIFT(73, 0),
    [278] = {.count = 1}, SHIFT(74, 0),
    [280] = {.count = 1}, SHIFT(75, 0),
    [282] = {.count = 1}, SHIFT(76, 0),
    [284] = {.count = 1}, SHIFT(77, 0),
    [286] = {.count = 1}, SHIFT(78, 0),
    [288] = {.count = 1}, SHIFT(79, 0),
    [290] = {.count = 1}, SHIFT(80, 0),
    [292] = {.count = 1}, SHIFT(81, 0),
    [294] = {.count = 1}, SHIFT(82, 0),
    [296] = {.count = 1}, REDUCE(sym_parameter_declaration, 2, 0),
    [298] = {.count = 1}, SHIFT(209, 0),
    [300] = {.count = 1}, SHIFT(210, 0),
    [302] = {.count = 1}, SHIFT(208, 0),
    [304] = {.count = 1}, SHIFT(203, 0),
    [306] = {.count = 1}, SHIFT(204, 0),
    [308] = {.count = 1}, SHIFT(98, 0),
    [310] = {.count = 1}, SHIFT(94, 0),
    [312] = {.count = 1}, SHIFT(90, 0),
    [314] = {.count = 1}, SHIFT(87, 0),
    [316] = {.count = 1}, SHIFT(88, 0),
    [318] = {.count = 1}, SHIFT(85, 0),
    [320] = {.count = 1}, SHIFT(83, 0),
    [322] = {.count = 1}, SHIFT(84, 0),
    [324] = {.count = 1}, SHIFT(86, 0),
    [326] = {.count = 1}, SHIFT(89, 0),
    [328] = {.count = 1}, SHIFT(91, 0),
    [330] = {.count = 1}, SHIFT(92, 0),
    [332] = {.count = 1}, SHIFT(93, 0),
    [334] = {.count = 1}, SHIFT(95, 0),
    [336] = {.count = 1}, SHIFT(96, 0),
    [338] = {.count = 1}, SHIFT(97, 0),
    [340] = {.count = 1}, REDUCE(sym_interface_type, 4, 0),
    [342] = {.count = 1}, SHIFT(99, 0),
    [344] = {.count = 1}, SHIFT(100, 0),
    [346] = {.count = 1}, SHIFT(101, 0),
    [348] = {.count = 1}, SHIFT(102, 0),
    [350] = {.count = 1}, SHIFT(103, 0),
    [352] = {.count = 1}, SHIFT(104, 0),
    [354] = {.count = 1}, SHIFT(111, 0),
    [356] = {.count = 1}, SHIFT(116, 0),
    [358] = {.count = 1}, SHIFT(117, 0),
    [360] = {.count = 1}, SHIFT(118, 0),
    [362] = {.count = 1}, SHIFT(119, 0),
    [364] = {.count = 1}, SHIFT(120, 0),
    [366] = {.count = 1}, SHIFT(121, 0),
    [368] = {.count = 1}, SHIFT(122, 0),
    [370] = {.count = 1}, SHIFT(123, 0),
    [372] = {.count = 1}, SHIFT(124, 0),
    [374] = {.count = 1}, SHIFT(125, 0),
    [376] = {.count = 1}, SHIFT(114, 0),
    [378] = {.count = 1}, SHIFT(113, 0),
    [380] = {.count = 1}, REDUCE(sym_struct_type, 3, 0),
    [382] = {.count = 1}, REDUCE(sym_identifier_list, 1, 0),
    [384] = {.count = 1}, SHIFT(105, 0),
    [386] = {.count = 1}, SHIFT(106, 0),
    [388] = {.count = 1}, REDUCE(sym_field_declaration, 1, 0),
    [390] = {.count = 1}, SHIFT(107, 0),
    [392] = {.count = 1}, SHIFT(108, 0),
    [394] = {.count = 1}, REDUCE(sym_field_declaration, 2, 0),
    [396] = {.count = 1}, REDUCE(sym_identifier_list, 2, 0),
    [398] = {.count = 1}, SHIFT(109, 0),
    [400] = {.count = 1}, REDUCE(sym__string_literal, 1, 0),
    [402] = {.count = 1}, REDUCE(aux_sym_identifier_list_repeat1, 2, 0),
    [404] = {.count = 1}, SHIFT(110, 0),
    [406] = {.count = 1}, REDUCE(aux_sym_identifier_list_repeat1, 3, 0),
    [408] = {.count = 1}, SHIFT(112, 0),
    [410] = {.count = 1}, REDUCE(sym_field_declaration, 3, 0),
    [412] = {.count = 1}, REDUCE(sym_struct_type, 4, 0),
    [414] = {.count = 1}, SHIFT(115, 0),
    [416] = {.count = 1}, REDUCE(aux_sym_struct_type_repeat1, 2, 0),
    [418] = {.count = 1}, REDUCE(aux_sym_struct_type_repeat1, 3, 0),
    [420] = {.count = 1}, SHIFT(190, 0),
    [422] = {.count = 1}, SHIFT(191, 0),
    [424] = {.count = 1}, SHIFT(189, 0),
    [426] = {.count = 1}, SHIFT(145, 0),
    [428] = {.count = 1}, SHIFT(148, 0),
    [430] = {.count = 1}, SHIFT(141, 0),
    [432] = {.count = 1}, SHIFT(137, 0),
    [434] = {.count = 1}, SHIFT(133, 0),
    [436] = {.count = 1}, SHIFT(130, 0),
    [438] = {.count = 1}, SHIFT(131, 0),
    [440] = {.count = 1}, SHIFT(128, 0),
    [442] = {.count = 1}, SHIFT(126, 0),
    [444] = {.count = 1}, SHIFT(127, 0),
    [446] = {.count = 1}, SHIFT(129, 0),
    [448] = {.count = 1}, SHIFT(132, 0),
    [450] = {.count = 1}, SHIFT(134, 0),
    [452] = {.count = 1}, SHIFT(135, 0),
    [454] = {.count = 1}, SHIFT(136, 0),
    [456] = {.count = 1}, SHIFT(138, 0),
    [458] = {.count = 1}, SHIFT(139, 0),
    [460] = {.count = 1}, SHIFT(140, 0),
    [462] = {.count = 1}, SHIFT(142, 0),
    [464] = {.count = 1}, SHIFT(143, 0),
    [466] = {.count = 1}, SHIFT(144, 0),
    [468] = {.count = 1}, SHIFT(152, 0),
    [470] = {.count = 1}, SHIFT(153, 0),
    [472] = {.count = 1}, SHIFT(154, 0),
    [474] = {.count = 1}, SHIFT(155, 0),
    [476] = {.count = 1}, SHIFT(156, 0),
    [478] = {.count = 1}, SHIFT(157, 0),
    [480] = {.count = 1}, SHIFT(158, 0),
    [482] = {.count = 1}, REDUCE(sym__expression, 1, 0),
    [484] = {.count = 1}, REDUCE(sym__primary_expression, 1, 0),
    [486] = {.count = 1}, SHIFT(151, 0),
    [488] = {.count = 1}, REDUCE(sym_int_literal, 1, 0),
    [490] = {.count = 1}, REDUCE(sym_slice_type, 3, 0),
    [492] = {.count = 1}, SHIFT(165, 0),
    [494] = {.count = 1}, SHIFT(166, 0),
    [496] = {.count = 1}, SHIFT(167, 0),
    [498] = {.count = 1}, SHIFT(168, 0),
    [500] = {.count = 1}, SHIFT(169, 0),
    [502] = {.count = 1}, SHIFT(170, 0),
    [504] = {.count = 1}, SHIFT(163, 0),
    [506] = {.count = 1}, SHIFT(164, 0),
    [508] = {.count = 1}, SHIFT(162, 0),
    [510] = {.count = 1}, SHIFT(161, 0),
    [512] = {.count = 1}, SHIFT(160, 0),
    [514] = {.count = 1}, SHIFT(159, 0),
    [516] = {.count = 1}, REDUCE(sym_binary_expression, 3, FRAGILE),
    [518] = {.count = 1}, REDUCE(sym_binary_expression, 3, 0),
    [520] = {.count = 1}, REDUCE(sym_array_type, 4, 0),
    [522] = {.count = 1}, SHIFT(188, 0),
    [524] = {.count = 1}, SHIFT(171, 0),
    [526] = {.count = 1}, SHIFT(172, 0),
    [528] = {.count = 1}, REDUCE(sym_expression_list, 1, 0),
    [530] = {.count = 1}, SHIFT(173, 0),
    [532] = {.count = 1}, SHIFT(174, 0),
    [534] = {.count = 1}, SHIFT(175, 0),
    [536] = {.count = 1}, SHIFT(176, 0),
    [538] = {.count = 1}, SHIFT(177, 0),
    [540] = {.count = 1}, SHIFT(178, 0),
    [542] = {.count = 1}, REDUCE(sym_expression_list, 2, 0),
    [544] = {.count = 1}, SHIFT(186, 0),
    [546] = {.count = 1}, SHIFT(184, 0),
    [548] = {.count = 1}, SHIFT(183, 0),
    [550] = {.count = 1}, SHIFT(182, 0),
    [552] = {.count = 1}, SHIFT(181, 0),
    [554] = {.count = 1}, SHIFT(180, 0),
    [556] = {.count = 1}, SHIFT(179, 0),
    [558] = {.count = 1}, SHIFT(185, 0),
    [560] = {.count = 1}, REDUCE(aux_sym_expression_list_repeat1, 2, 0),
    [562] = {.count = 1}, REDUCE(aux_sym_expression_list_repeat1, 3, 0),
    [564] = {.count = 1}, SHIFT(187, 0),
    [566] = {.count = 1}, REDUCE(sym_call_expression, 4, 0),
    [568] = {.count = 1}, REDUCE(sym_pointer_type, 2, 0),
    [570] = {.count = 1}, SHIFT(198, 0),
    [572] = {.count = 1}, REDUCE(sym_function_type, 2, 0),
    [574] = {.count = 1}, SHIFT(199, 0),
    [576] = {.count = 1}, SHIFT(192, 0),
    [578] = {.count = 1}, SHIFT(193, 0),
    [580] = {.count = 1}, SHIFT(194, 0),
    [582] = {.count = 1}, REDUCE(sym_parameters, 3, 0),
    [584] = {.count = 1}, SHIFT(196, 0),
    [586] = {.count = 1}, SHIFT(197, 0),
    [588] = {.count = 1}, REDUCE(sym__parameter_list, 3, 0),
    [590] = {.count = 1}, REDUCE(sym_function_type, 3, 0),
    [592] = {.count = 1}, SHIFT(200, 0),
    [594] = {.count = 1}, SHIFT(201, 0),
    [596] = {.count = 1}, SHIFT(202, 0),
    [598] = {.count = 1}, SHIFT(206, 0),
    [600] = {.count = 1}, SHIFT(205, 0),
    [602] = {.count = 1}, SHIFT(207, 0),
    [604] = {.count = 1}, SHIFT(214, 0),
    [606] = {.count = 1}, SHIFT(215, 0),
    [608] = {.count = 1}, SHIFT(211, 0),
    [610] = {.count = 1}, SHIFT(212, 0),
    [612] = {.count = 1}, SHIFT(213, 0),
    [614] = {.count = 1}, SHIFT(216, 0),
    [616] = {.count = 1}, SHIFT(217, 0),
    [618] = {.count = 1}, SHIFT(218, 0),
    [620] = {.count = 1}, REDUCE(aux_sym_interface_type_repeat1, 3, 0),
    [622] = {.count = 1}, REDUCE(sym_method_spec, 3, 0),
    [624] = {.count = 1}, SHIFT(223, 0),
    [626] = {.count = 1}, SHIFT(224, 0),
    [628] = {.count = 1}, SHIFT(225, 0),
    [630] = {.count = 1}, SHIFT(228, 0),
    [632] = {.count = 1}, SHIFT(229, 0),
    [634] = {.count = 1}, SHIFT(230, 0),
    [636] = {.count = 1}, SHIFT(234, 0),
    [638] = {.count = 1}, SHIFT(233, 0),
    [640] = {.count = 1}, SHIFT(235, 0),
    [642] = {.count = 1}, SHIFT(242, 0),
    [644] = {.count = 1}, SHIFT(243, 0),
    [646] = {.count = 1}, SHIFT(239, 0),
    [648] = {.count = 1}, SHIFT(240, 0),
    [650] = {.count = 1}, SHIFT(241, 0),
    [652] = {.count = 1}, SHIFT(244, 0),
    [654] = {.count = 1}, SHIFT(245, 0),
    [656] = {.count = 1}, SHIFT(246, 0),
    [658] = {.count = 1}, SHIFT(248, 0),
    [660] = {.count = 1}, SHIFT(250, 0),
    [662] = {.count = 1}, SHIFT(251, 0),
    [664] = {.count = 1}, SHIFT(252, 0),
    [666] = {.count = 1}, SHIFT(254, 0),
    [668] = {.count = 1}, SHIFT(255, 0),
    [670] = {.count = 1}, SHIFT(256, 0),
    [672] = {.count = 1}, SHIFT(260, 0),
    [674] = {.count = 1}, SHIFT(259, 0),
    [676] = {.count = 1}, SHIFT(261, 0),
    [678] = {.count = 1}, SHIFT(264, 0),
    [680] = {.count = 1}, SHIFT(269, 0),
    [682] = {.count = 1}, SHIFT(268, 0),
    [684] = {.count = 1}, REDUCE(sym_type_declaration, 3, 0),
    [686] = {.count = 1}, REDUCE(sym_type_declaration, 4, 0),
    [688] = {.count = 1}, SHIFT(270, 0),
    [690] = {.count = 1}, REDUCE(aux_sym_type_declaration_repeat1, 2, 0),
    [692] = {.count = 1}, REDUCE(aux_sym_type_declaration_repeat1, 3, 0),
    [694] = {.count = 1}, SHIFT(352, 0),
    [696] = {.count = 1}, SHIFT(349, 0),
    [698] = {.count = 1}, SHIFT(350, 0),
    [700] = {.count = 1}, SHIFT(274, 0),
    [702] = {.count = 1}, SHIFT(275, 0),
    [704] = {.count = 1}, SHIFT(279, 0),
    [706] = {.count = 1}, SHIFT(280, 0),
    [708] = {.count = 1}, SHIFT(281, 0),
    [710] = {.count = 1}, REDUCE(sym_function_declaration, 3, 0),
    [712] = {.count = 1}, SHIFT(282, 0),
    [714] = {.count = 1}, SHIFT(283, 0),
    [716] = {.count = 1}, SHIFT(284, 0),
    [718] = {.count = 1}, SHIFT(285, 0),
    [720] = {.count = 1}, SHIFT(286, 0),
    [722] = {.count = 1}, SHIFT(287, 0),
    [724] = {.count = 1}, SHIFT(288, 0),
    [726] = {.count = 1}, SHIFT(289, 0),
    [728] = {.count = 1}, SHIFT(290, 0),
    [730] = {.count = 1}, SHIFT(291, 0),
    [732] = {.count = 1}, SHIFT(292, 0),
    [734] = {.count = 1}, SHIFT(276, 0),
    [736] = {.count = 1}, SHIFT(277, 0),
    [738] = {.count = 1}, SHIFT(278, 0),
    [740] = {.count = 1}, SHIFT(348, 0),
    [742] = {.count = 1}, REDUCE(sym_function_declaration, 4, 0),
    [744] = {.count = 1}, SHIFT(345, 0),
    [746] = {.count = 1}, SHIFT(346, 0),
    [748] = {.count = 1}, SHIFT(343, 0),
    [750] = {.count = 1}, SHIFT(342, 0),
    [752] = {.count = 1}, SHIFT(337, 0),
    [754] = {.count = 1}, SHIFT(338, 0),
    [756] = {.count = 1}, SHIFT(333, 0),
    [758] = {.count = 1}, SHIFT(308, 0),
    [760] = {.count = 1}, SHIFT(309, 0),
    [762] = {.count = 1}, SHIFT(310, 0),
    [764] = {.count = 1}, SHIFT(311, 0),
    [766] = {.count = 1}, SHIFT(312, 0),
    [768] = {.count = 1}, SHIFT(313, 0),
    [770] = {.count = 1}, SHIFT(314, 0),
    [772] = {.count = 1}, SHIFT(315, 0),
    [774] = {.count = 1}, SHIFT(316, 0),
    [776] = {.count = 1}, SHIFT(304, 0),
    [778] = {.count = 1}, SHIFT(300, 0),
    [780] = {.count = 1}, SHIFT(297, 0),
    [782] = {.count = 1}, SHIFT(298, 0),
    [784] = {.count = 1}, SHIFT(295, 0),
    [786] = {.count = 1}, SHIFT(293, 0),
    [788] = {.count = 1}, SHIFT(294, 0),
    [790] = {.count = 1}, SHIFT(296, 0),
    [792] = {.count = 1}, SHIFT(299, 0),
    [794] = {.count = 1}, SHIFT(301, 0),
    [796] = {.count = 1}, SHIFT(302, 0),
    [798] = {.count = 1}, SHIFT(303, 0),
    [800] = {.count = 1}, SHIFT(305, 0),
    [802] = {.count = 1}, SHIFT(306, 0),
    [804] = {.count = 1}, SHIFT(307, 0),
    [806] = {.count = 1}, REDUCE(sym__statement, 1, 0),
    [808] = {.count = 1}, SHIFT(331, 0),
    [810] = {.count = 1}, SHIFT(318, 0),
    [812] = {.count = 1}, SHIFT(319, 0),
    [814] = {.count = 1}, SHIFT(320, 0),
    [816] = {.count = 1}, SHIFT(321, 0),
    [818] = {.count = 1}, SHIFT(322, 0),
    [820] = {.count = 1}, SHIFT(323, 0),
    [822] = {.count = 1}, SHIFT(317, 0),
    [824] = {.count = 1}, REDUCE(sym_block, 2, 0),
    [826] = {.count = 1}, REDUCE(sym_block, 3, 0),
    [828] = {.count = 1}, SHIFT(329, 0),
    [830] = {.count = 1}, SHIFT(328, 0),
    [832] = {.count = 1}, SHIFT(327, 0),
    [834] = {.count = 1}, SHIFT(326, 0),
    [836] = {.count = 1}, SHIFT(325, 0),
    [838] = {.count = 1}, SHIFT(324, 0),
    [840] = {.count = 1}, SHIFT(330, 0),
    [842] = {.count = 1}, SHIFT(332, 0),
    [844] = {.count = 1}, REDUCE(aux_sym_block_repeat1, 2, 0),
    [846] = {.count = 1}, REDUCE(aux_sym_block_repeat1, 3, 0),
    [848] = {.count = 1}, SHIFT(334, 0),
    [850] = {.count = 1}, SHIFT(335, 0),
    [852] = {.count = 1}, SHIFT(336, 0),
    [854] = {.count = 1}, SHIFT(340, 0),
    [856] = {.count = 1}, SHIFT(339, 0),
    [858] = {.count = 1}, SHIFT(341, 0),
    [860] = {.count = 1}, SHIFT(344, 0),
    [862] = {.count = 1}, SHIFT(347, 0),
    [864] = {.count = 1}, REDUCE(sym_function_declaration, 5, 0),
    [866] = {.count = 1}, SHIFT(351, 0),
    [868] = {.count = 1}, SHIFT(353, 0),
    [870] = {.count = 1}, SHIFT(354, 0),
    [872] = {.count = 1}, SHIFT(355, 0),
    [874] = {.count = 1}, REDUCE(sym_method_declaration, 4, 0),
    [876] = {.count = 1}, SHIFT(356, 0),
    [878] = {.count = 1}, REDUCE(sym_method_declaration, 5, 0),
    [880] = {.count = 1}, REDUCE(sym_method_declaration, 6, 0),
    [882] = {.count = 1}, REDUCE(sym_var_declaration, 2, 0),
    [884] = {.count = 1}, SHIFT(371, 0),
    [886] = {.count = 1}, SHIFT(372, 0),
    [888] = {.count = 1}, SHIFT(373, 0),
    [890] = {.count = 1}, SHIFT(374, 0),
    [892] = {.count = 1}, SHIFT(375, 0),
    [894] = {.count = 1}, SHIFT(376, 0),
    [896] = {.count = 1}, SHIFT(377, 0),
    [898] = {.count = 1}, SHIFT(378, 0),
    [900] = {.count = 1}, SHIFT(379, 0),
    [902] = {.count = 1}, SHIFT(380, 0),
    [904] = {.count = 1}, SHIFT(381, 0),
    [906] = {.count = 1}, SHIFT(382, 0),
    [908] = {.count = 1}, SHIFT(365, 0),
    [910] = {.count = 1}, SHIFT(366, 0),
    [912] = {.count = 1}, SHIFT(367, 0),
    [914] = {.count = 1}, SHIFT(361, 0),
    [916] = {.count = 1}, SHIFT(362, 0),
    [918] = {.count = 1}, SHIFT(363, 0),
    [920] = {.count = 1}, SHIFT(364, 0),
    [922] = {.count = 1}, SHIFT(369, 0),
    [924] = {.count = 1}, SHIFT(368, 0),
    [926] = {.count = 1}, REDUCE(sym_var_declaration, 3, 0),
    [928] = {.count = 1}, REDUCE(sym_var_declaration, 4, 0),
    [930] = {.count = 1}, SHIFT(370, 0),
    [932] = {.count = 1}, REDUCE(aux_sym_var_declaration_repeat1, 2, 0),
    [934] = {.count = 1}, REDUCE(aux_sym_var_declaration_repeat1, 3, 0),
    [936] = {.count = 1}, REDUCE(sym_var_spec, 2, 0),
    [938] = {.count = 1}, SHIFT(441, 0),
    [940] = {.count = 1}, SHIFT(418, 0),
    [942] = {.count = 1}, SHIFT(419, 0),
    [944] = {.count = 1}, SHIFT(420, 0),
    [946] = {.count = 1}, SHIFT(421, 0),
    [948] = {.count = 1}, SHIFT(422, 0),
    [950] = {.count = 1}, SHIFT(423, 0),
    [952] = {.count = 1}, SHIFT(408, 0),
    [954] = {.count = 1}, SHIFT(409, 0),
    [956] = {.count = 1}, SHIFT(407, 0),
    [958] = {.count = 1}, SHIFT(402, 0),
    [960] = {.count = 1}, SHIFT(403, 0),
    [962] = {.count = 1}, SHIFT(398, 0),
    [964] = {.count = 1}, SHIFT(394, 0),
    [966] = {.count = 1}, SHIFT(390, 0),
    [968] = {.count = 1}, SHIFT(387, 0),
    [970] = {.count = 1}, SHIFT(388, 0),
    [972] = {.count = 1}, SHIFT(385, 0),
    [974] = {.count = 1}, SHIFT(383, 0),
    [976] = {.count = 1}, SHIFT(384, 0),
    [978] = {.count = 1}, SHIFT(386, 0),
    [980] = {.count = 1}, SHIFT(389, 0),
    [982] = {.count = 1}, SHIFT(391, 0),
    [984] = {.count = 1}, SHIFT(392, 0),
    [986] = {.count = 1}, SHIFT(393, 0),
    [988] = {.count = 1}, SHIFT(395, 0),
    [990] = {.count = 1}, SHIFT(396, 0),
    [992] = {.count = 1}, SHIFT(397, 0),
    [994] = {.count = 1}, SHIFT(399, 0),
    [996] = {.count = 1}, SHIFT(400, 0),
    [998] = {.count = 1}, SHIFT(401, 0),
    [1000] = {.count = 1}, SHIFT(405, 0),
    [1002] = {.count = 1}, SHIFT(404, 0),
    [1004] = {.count = 1}, SHIFT(406, 0),
    [1006] = {.count = 1}, SHIFT(413, 0),
    [1008] = {.count = 1}, SHIFT(414, 0),
    [1010] = {.count = 1}, SHIFT(410, 0),
    [1012] = {.count = 1}, SHIFT(411, 0),
    [1014] = {.count = 1}, SHIFT(412, 0),
    [1016] = {.count = 1}, SHIFT(415, 0),
    [1018] = {.count = 1}, SHIFT(416, 0),
    [1020] = {.count = 1}, SHIFT(417, 0),
    [1022] = {.count = 1}, REDUCE(sym_var_spec, 3, 0),
    [1024] = {.count = 1}, SHIFT(424, 0),
    [1026] = {.count = 1}, SHIFT(425, 0),
    [1028] = {.count = 1}, SHIFT(426, 0),
    [1030] = {.count = 1}, SHIFT(427, 0),
    [1032] = {.count = 1}, SHIFT(428, 0),
    [1034] = {.count = 1}, SHIFT(429, 0),
    [1036] = {.count = 1}, SHIFT(430, 0),
    [1038] = {.count = 1}, SHIFT(431, 0),
    [1040] = {.count = 1}, SHIFT(439, 0),
    [1042] = {.count = 1}, SHIFT(437, 0),
    [1044] = {.count = 1}, SHIFT(436, 0),
    [1046] = {.count = 1}, SHIFT(435, 0),
    [1048] = {.count = 1}, SHIFT(434, 0),
    [1050] = {.count = 1}, SHIFT(433, 0),
    [1052] = {.count = 1}, SHIFT(432, 0),
    [1054] = {.count = 1}, SHIFT(438, 0),
    [1056] = {.count = 1}, SHIFT(440, 0),
    [1058] = {.count = 1}, SHIFT(442, 0),
    [1060] = {.count = 1}, REDUCE(sym_var_spec, 4, 0),
    [1062] = {.count = 1}, REDUCE(sym_const_declaration, 2, 0),
    [1064] = {.count = 1}, SHIFT(452, 0),
    [1066] = {.count = 1}, SHIFT(453, 0),
    [1068] = {.count = 1}, SHIFT(454, 0),
    [1070] = {.count = 1}, SHIFT(455, 0),
    [1072] = {.count = 1}, SHIFT(456, 0),
    [1074] = {.count = 1}, SHIFT(457, 0),
    [1076] = {.count = 1}, SHIFT(458, 0),
    [1078] = {.count = 1}, SHIFT(459, 0),
    [1080] = {.count = 1}, SHIFT(460, 0),
    [1082] = {.count = 1}, SHIFT(461, 0),
    [1084] = {.count = 1}, SHIFT(462, 0),
    [1086] = {.count = 1}, SHIFT(463, 0),
    [1088] = {.count = 1}, SHIFT(446, 0),
    [1090] = {.count = 1}, SHIFT(447, 0),
    [1092] = {.count = 1}, SHIFT(448, 0),
    [1094] = {.count = 1}, SHIFT(450, 0),
    [1096] = {.count = 1}, SHIFT(449, 0),
    [1098] = {.count = 1}, REDUCE(sym_const_declaration, 3, 0),
    [1100] = {.count = 1}, REDUCE(sym_const_declaration, 4, 0),
    [1102] = {.count = 1}, SHIFT(451, 0),
    [1104] = {.count = 1}, REDUCE(aux_sym_const_declaration_repeat1, 2, 0),
    [1106] = {.count = 1}, REDUCE(aux_sym_const_declaration_repeat1, 3, 0),
    [1108] = {.count = 1}, SHIFT(500, 0),
    [1110] = {.count = 1}, SHIFT(499, 0),
    [1112] = {.count = 1}, SHIFT(489, 0),
    [1114] = {.count = 1}, SHIFT(490, 0),
    [1116] = {.count = 1}, SHIFT(488, 0),
    [1118] = {.count = 1}, SHIFT(483, 0),
    [1120] = {.count = 1}, SHIFT(484, 0),
    [1122] = {.count = 1}, SHIFT(479, 0),
    [1124] = {.count = 1}, SHIFT(475, 0),
    [1126] = {.count = 1}, SHIFT(471, 0),
    [1128] = {.count = 1}, SHIFT(468, 0),
    [1130] = {.count = 1}, SHIFT(469, 0),
    [1132] = {.count = 1}, SHIFT(466, 0),
    [1134] = {.count = 1}, SHIFT(464, 0),
    [1136] = {.count = 1}, SHIFT(465, 0),
    [1138] = {.count = 1}, SHIFT(467, 0),
    [1140] = {.count = 1}, SHIFT(470, 0),
    [1142] = {.count = 1}, SHIFT(472, 0),
    [1144] = {.count = 1}, SHIFT(473, 0),
    [1146] = {.count = 1}, SHIFT(474, 0),
    [1148] = {.count = 1}, SHIFT(476, 0),
    [1150] = {.count = 1}, SHIFT(477, 0),
    [1152] = {.count = 1}, SHIFT(478, 0),
    [1154] = {.count = 1}, SHIFT(480, 0),
    [1156] = {.count = 1}, SHIFT(481, 0),
    [1158] = {.count = 1}, SHIFT(482, 0),
    [1160] = {.count = 1}, SHIFT(486, 0),
    [1162] = {.count = 1}, SHIFT(485, 0),
    [1164] = {.count = 1}, SHIFT(487, 0),
    [1166] = {.count = 1}, SHIFT(494, 0),
    [1168] = {.count = 1}, SHIFT(495, 0),
    [1170] = {.count = 1}, SHIFT(491, 0),
    [1172] = {.count = 1}, SHIFT(492, 0),
    [1174] = {.count = 1}, SHIFT(493, 0),
    [1176] = {.count = 1}, SHIFT(496, 0),
    [1178] = {.count = 1}, SHIFT(497, 0),
    [1180] = {.count = 1}, SHIFT(498, 0),
    [1182] = {.count = 1}, REDUCE(sym_const_spec, 3, 0),
    [1184] = {.count = 1}, SHIFT(501, 0),
    [1186] = {.count = 1}, REDUCE(sym_const_spec, 4, 0),
    [1188] = {.count = 1}, REDUCE(sym_import_declaration, 2, 0),
    [1190] = {.count = 1}, REDUCE(sym_import_spec, 1, 0),
    [1192] = {.count = 1}, SHIFT(508, 0),
    [1194] = {.count = 1}, SHIFT(509, 0),
    [1196] = {.count = 1}, SHIFT(510, 0),
    [1198] = {.count = 1}, SHIFT(511, 0),
    [1200] = {.count = 1}, SHIFT(512, 0),
    [1202] = {.count = 1}, SHIFT(507, 0),
    [1204] = {.count = 1}, REDUCE(sym_import_spec, 2, 0),
    [1206] = {.count = 1}, SHIFT(515, 0),
    [1208] = {.count = 1}, SHIFT(514, 0),
    [1210] = {.count = 1}, REDUCE(sym_import_declaration, 3, 0),
    [1212] = {.count = 1}, SHIFT(513, 0),
    [1214] = {.count = 1}, REDUCE(sym_import_declaration, 4, 0),
    [1216] = {.count = 1}, SHIFT(516, 0),
    [1218] = {.count = 1}, REDUCE(aux_sym_import_declaration_repeat1, 2, 0),
    [1220] = {.count = 1}, REDUCE(aux_sym_import_declaration_repeat1, 3, 0),
    [1222] = {.count = 1}, REDUCE(sym_source_file, 3, 0),
    [1224] = {.count = 1}, SHIFT(519, 0),
    [1226] = {.count = 1}, REDUCE(aux_sym_source_file_repeat2, 2, 0),
    [1228] = {.count = 1}, REDUCE(aux_sym_source_file_repeat2, 3, 0),
    [1230] = {.count = 1}, REDUCE(aux_sym_source_file_repeat1, 2, 0),
};

#pragma GCC diagnostic pop

EXPORT_LANGUAGE(ts_language_go);