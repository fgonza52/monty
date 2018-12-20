#include "monty.h"
#include "ops_array.h"

void exec_line_ops(char *line, size_t line_num)
{
	char *cmd = NULL, *arg = NULL;

	cmd = strtok(line, DELIMS);
	fetch_instruction(cmd, line_num);
	(void)arg;
}

void fetch_instruction(char *cmd, size_t line_num)
{
	for (int i = 0; ops[i].opcode; ++i)
	{
		if (strcmp(cmd, ops[i].opcode) == 0)
		{
			ops[i].f(&global.stack, line_num);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", (int)line_num, cmd);
	exit(EXIT_FAILURE);
}


