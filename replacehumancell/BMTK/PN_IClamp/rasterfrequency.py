from bmtk.analyzer.spike_trains import raster_plot, rates_plot

rates_plot('network/SPWR_biophysical_nodes.h5', 'network/SPWR_biophysical_node_types.csv', 'output/spikes.h5', group_key='pop_name', smoothed=True)

