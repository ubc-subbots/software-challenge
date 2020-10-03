from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return launch.LaunchDescription([
        Node(
            package='turtlesim',
            namespace='turtlesim1',
            executable='turtlesim_node',
            name='sim'
        ),
        Node(
            package='turtle_package',
            executable='turtle_sine',
            name='sine'
        ),
    ])
