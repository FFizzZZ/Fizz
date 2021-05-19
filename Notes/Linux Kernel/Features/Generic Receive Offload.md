# Generic Receive Offload

```
gro_result_t napi_gro_receive(struct napi_struct *napi, struct sk_buff *skb)
{
	skb_mark_napi_id(skb, napi);
	trace_napi_gro_receive_entry(skb);

	skb_gro_reset_offset(skb);

	return napi_skb_finish(dev_gro_receive(napi, skb), skb);
}
```
