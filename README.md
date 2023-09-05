# Unreal-Engine-Memory-Guard

Unreal-Engine-Memory-Guard is a free and open-source plugin for Unreal Engine aimed at providing enhanced security measures. This plugin introduces a mechanism to guard in-memory values using strong encryption and data integrity verification.

![image](https://github.com/ArmainAP/Unreal-Engine-Memory-Guard/assets/26823759/322dcc33-bfed-4306-8445-df77b9b41915)


## Features

- **Secure Data Storage**: Uses AES encryption to ensure that in-memory values are stored securely.
  
- **Data Integrity**: The signature (hash) of each value ensures that the data remains untampered during its lifecycle in memory.
  
- **Base64 Encoding**: Uses Base64 encoding to safely represent encrypted data as a string.
  
- **Template Implementation**: Works seamlessly with any trivially copyable datatype.
  
- **Blueprint Integration**: Supports a blueprint wrapper, enabling easy use within blueprints. It uses wildcard property values, making it adaptable for different data types.
  
- **Easy Integration**: With a familiar UE-style API, integrating and using Memory Guard is a breeze for any developer familiar with Unreal Engine.
  
- **Reliable Decryption**: Only returns the decrypted value if the signature matches, ensuring data hasn't been tampered with.
  
## Installation

1. Clone or download the repository.
2. Copy the plugin to your Unreal Engine project's `Plugins` directory. If you don’t have one, create it.
3. Restart the Unreal Engine Editor.
4. Enable the Unreal-Engine-Memory-Guard plugin via the Plugin Manager.

## Usage

- After installation, the `FGuardedValue` template can be used in your code.
  
- Initialize the guarded value using the `SetValue` method, which encrypts and hashes the provided value.
  
- Retrieve the original data using the `GetValue` method, which decrypts the data only if its integrity is maintained.
  
- For Blueprint users, use the provided blueprint wrapper to easily integrate and use the guarded values in your blueprints.
  
- You can use this struct anywhere in your code where you want to ensure that specific in-memory values remain safe and unaltered.

## Contributing

We welcome contributions! If you have a feature request, bug report, or want to improve the plugin, please open an issue or send a pull request.

## License

This project is released under the AGPL-3.0 license.

If you require a different license or have questions related to licensing, please reach out to adrian.popoviciu@katcodelabs.com.

## Credits

Created by Adrian-Marian Popoviciu. A special thanks to the Unreal Engine community for their valuable feedback and contributions. 

Kudos to [PicoSHA2](https://github.com/okdshin/PicoSHA2) contributors for their robust SHA256 generation, which has been instrumental for the data integrity features of this plugin.
