import requests

import click


@click.command()
@click.option('--location')

def climate_currrent(location):
    
    url="http://api.weatherapi.com/v1/current.json?key=57b26affc34349b4bf8192954252810&q=London"

    data={'location': {'name': location, 'region': 'City of London, Greater London', 'country': 'United Kingdom', 'lat': 51.5171, 'lon': -0.1062, 'tz_id': 'Europe/London', 'localtime_epoch': 1761679906, 'localtime': '2025-10-28 19:31'}, 'current': {'last_updated_epoch': 1761679800, 'last_updated': '2025-10-28 19:30', 'temp_c': 12.2, 'temp_f': 54.0, 'is_day': 0, 'condition': {'text': 'Partly Cloudy', 'icon': 
    '//cdn.weatherapi.com/weather/64x64/night/116.png', 'code': 1003}, 'wind_mph': 9.4, 'wind_kph': 15.1, 'wind_degree': 241, 'wind_dir': 'WSW', 'pressure_mb': 1007.0, 'pressure_in': 29.74, 'precip_mm': 0.0, 'precip_in': 0.0, 'humidity': 71, 'cloud': 0, 'feelslike_c': 10.6, 'feelslike_f': 51.1, 'windchill_c': 9.9, 'windchill_f': 49.8, 'heatindex_c': 11.6, 'heatindex_f': 52.9, 'dewpoint_c': 6.2, 'dewpoint_f': 43.1, 'vis_km': 10.0, 'vis_miles': 6.0, 'uv': 0.0, 'gust_mph': 14.1, 'gust_kph': 22.7, 'short_rad': 0, 'diff_rad': 0, 'dni': 0, 'gti': 0}}

    print(data)


if __name__=="__main__":
    climate_currrent('London')