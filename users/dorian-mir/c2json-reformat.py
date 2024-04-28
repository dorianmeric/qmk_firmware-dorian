

import json

with open('qmkconfig-dorianmir.json', 'r+') as f:
    data = json.load(f)
    data['layout'] = "LAYOUT_split_3x5_2"

    for layer in data["layers"]:
        layer.pop(30)
        layer.pop(30)
        layer.pop(30) # removes the double-thumb left
        layer.pop() 
        layer.pop()
        layer.pop() # removes the double-thumb right

with open('qmkconfig-dorianmir(fixed).json', 'w+') as f2:
    f2.seek(0)        # <--- should reset file position to the beginning.
    json.dump(data, f2, indent=4)
    f2.truncate()     # remove remaining part


