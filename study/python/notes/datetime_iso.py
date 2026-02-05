from datetime import datetime
import json

with open('data_2.json') as fh:
    data1 = json.load(fh)


with open('data_1.json') as fh:
    data2 = json.load(fh)


def convert_format2(data):

    result = {
        "deviceID": data["device"]["id"],
        "deviceType": data["device"]["type"],
        "timestamp": iso_to_millsec(data["timestamp"]), 
        "location": {
            'country': data["country"],
            'city': data["city"],
            'area': data["area"],
            'factory': data["factory"],
            'section': data["section"]
        },
        "data":{
            "status": data["data"]["status"],
            "temperature": data["data"]["temperature"]
        }
        
    }

    return result


def convert_format1(data):

    holder=data["location"].split('/')

    result={
        "deviceID": data["deviceID"],
        "deviceType": data["deviceType"],
        "timestamp": data["timestamp"], 
        
        "location": {
            'country': holder[0],
            'city': holder[1],
            'area': holder[2],
            'factory': holder[3],
            'section': holder[4]
        },
        "data":{
            "status": data["operationStatus"],
            "temperature": data["temp"]
        }
    }


    return result


def iso_to_millsec(timestamp):

    dtc = datetime.fromisoformat(timestamp.replace('Z', '+00:00'))  # here ds in now a  datetime object (year-month-day T hour:minute:second.microsecond)) were Z repleced by +00:00 as we are in UTC
    return(dtc.timestamp() * 1000 ) #here timestamp() method is used to get the time in seconds since the epoch as a floating point number.


def millisec_to_iso(timestamp):
    return datetime.fromtimestamp(int(timestamp)/1000).isoformat().replace("+00:00", "Z")   # so here first with the  help of fromtimestamp we  convert secouns to a dat time object .here we convert the timestamp to a datetime object and then to a string in ISO format


def main(data):
    if "device" in data:    #here we check in the given json is there "device" key is yes then then iin the format 2 as you see in format2 thsi key is here
        return convert_format2(data)
    else:
        return convert_format1(data)


if __name__ == "__main__":
    import json

    with open("data-1.json") as f:
        data1 = json.load(f)

    with open("data-2.json") as f:
        data2 = json.load(f)

    print(main(data1))
    print(main(data2))
