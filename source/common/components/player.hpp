#pragma once

#include "../ecs/component.hpp"

#include <glm/mat4x4.hpp>

namespace our
{

    // This component denotes that any renderer should draw the scene relative to this camera.
    // We do not define the eye, center or up here since they can be extracted from the entity local to world matrix
    class PlayerComponent : public Component
    {
    public:
        float health;
        int coins = 0;
        int totalCoins ;
        int state=4;
        // glm::vec3 angularVelocity;
        // The ID of this component type is "Camera"
        static std::string getID() { return "Player"; }

        void deserialize(const nlohmann::json &data) override;
        int getPlayerState(){
            return state;
        }
        // Creates and returns the camera view matrix
        glm::mat4 getViewMatrix() const;
    };

} // namespace our
