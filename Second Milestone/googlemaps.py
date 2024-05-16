import gmplot
import pandas as pd
import os, sys, string

df = pd.read_csv (r'serial_data.CSV')
lat =df['lat'].tolist()
lon =df['long'].tolist()

# Create the map plotter:
gmap = gmplot.GoogleMapPlotter(lat[0], lon[0], 18, apikey="AIzaSyCu-ZEoB8OGYDM3eb31skY43HTRoqdrftA")

gmap.scatter(lat, lon, color='#3B0B39', size=0.2, marker=False)
gmap.plot(lat,lon,'#ff00f0',edge_width=5)

# Mark a hidden gem:
gmap.marker(lat[0], lon[0], color='cornflowerblue')
gmap.marker(lat[-1], lon[-1], color='#ff0000')

# Draw the map:
gmap.draw('map.html')
os.startfile("map.html")

