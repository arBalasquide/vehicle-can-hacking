# VehicleHacking

Centralized Linux SocketCAN C++ wrapper aiming to be quick and easy to get someone started on writing programs for their car.

## Is this just another CAN tool?

No, there's already plenty of CAN tools that are great for reverse engineering. This is just a wrapper that contains logic, keys, and information for different cars that will allow a user to quickly sketch a sample program for their project. 

There's a lot of information online about how to reverse engineer the canbus on a vehicle but not a lot of examples with real vehicles, and, for example, it looks to provide answers with code to questions such as "What does the CAN message to unlock my Ford Forester 2011 look like?"

This repo's goal is maintain a variety of examples, using the API provided, for controlling and accessing features of different makes and models and hopefully others are able to contribute their knowledge.

## Legal Disclaimer

Cars have diagnostic features that can be dangerous if done incorrectly, such as making the vehicle move or redlining the engine. Please exercise caution, even if it means putting the car on jackstands or any other precautionary actions. That being said, I am just one maintainer with access to only one car, so I cannot guarantee for this API to work perfectly for every vehicle.