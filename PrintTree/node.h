#ifndef NODE_H
#define NODE_H
#define PRINTF_TYPENODE printf("The types Node is %3d %2d %2d %2d ",p->row,p->column,p->type,p->var_type);
#define PRINTF_OP_NODE printf("The opera Node is %3d %2d XX XX ",op.name,op.num);
#define PRINTF_CONTENT_NODE printf("The conte Node is %3d %2d %2d %2d ",p->row,p->column,p->type,p->content);
#define PRINTF_INDEX_NODE printf("The index Node is %3d %2d %2d %s ",p->row,p->column,p->type,p->string);
#define PRINTF_NULL_NODE printf("The null Node is XXX XX XX XX ");
#define MAXQUEUE 1000
/* 定义树结点的权举类型 */ 
typedef enum { TYPE_CONSTANT, TYPE_INDENTIFER, TYPE_OP,TYPE_VAR } NodeEnum;

/* 操作符 */ 
typedef struct {
	int name;		/* 操作符名称 */
	int num;		/* 操作元个数 */
	struct NodeTag **nodeArray;	/* 操作元地址 可扩展 */
} OpNode;
// Content Identifer 没有next节点
typedef struct NodeTag {
	NodeEnum type;		/* 树结点类型 */
	int row; // 所位于的行
	int column; // 所位于的列
	/* Union 必须是最后一个成员 */ 
	union {
		int var_type; /*0 代表 int 1 代表 void  */
		int content;	/* 内容 */
		char* string; /*字符串*/
		OpNode op;	/* 操作符对象 */
	};
} Node;
typedef struct  
{
	int row; // 所位于的行
	int column; // 所位于的列
	union {
		int value;
		char* string;
	};
} LexNode;
//judge lex or yacc has error or not
extern int hasError;
#endif