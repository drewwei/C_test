#define BUFLEN	1024
#defien NEXT_PLACE (i)	((i+1)%BUFLEN)
static buf_type	g_events[1024];
static int g_r = 0;
static int g_w = 0;
//缓冲区空？
static int is_buf_empty(void)
{
	return g_r == g_w;
}
//缓冲区满？
static int is_buf_full(void)
{
	return NEXT_PLACE(g_w) == g_r;
}
//写缓冲区
int fifo_write(p_irda_raw_event pd)
{
	if (is_buf_full())
		return -1;
	g_events[g_w] = *pd;
	g_w = NEXT_PLACE(g_w);
	return 0;
}
//读缓冲区
int fifo_read(p_irda_raw_event pd)
{
	if (is_buf_empty())
		return -1;
	*pd = g_events[g_r];
	g_r = NEXT_PLACE(g_r);
	return 0;
}
