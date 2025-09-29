# speed of aircrafts is given in *knots*
# travelTime is in *minutes*
# travel distance should be returned in *kilometers*


def travel_distance(avg_speed, travel_time):
    avg_speed *= 1.150779
    KM_PER_MILE = 1.609344

    travel_hours = travel_time / 60
    travel_miles = avg_speed * travel_hours
    travel_kms = travel_miles * KM_PER_MILE
    return travel_kms
