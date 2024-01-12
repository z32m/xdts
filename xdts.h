#ifndef __xdts_h__
#define __xdts_h__

#define L(_node_label) DT_NODELABEL(_node_label)
#define DEFINE_DEVICE(_node_label) const struct device *_node_label = DEVICE_DT_GET(L(_node_label))

#endif