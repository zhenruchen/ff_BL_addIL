from bmtk.analyzer.spike_trains import raster_plot, rates_plot
import matplotlib.pyplot as plt
raster_plot('network/ff_ff_nodes.h5', 'network/ff_ff_node_types.csv', 'PN_IClamp/output/spikes.h5', group_key='pop_name')
plt.show()
