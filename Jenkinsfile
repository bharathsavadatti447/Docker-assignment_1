pipeline {
    agent { label 'Node-Linux' }

    environment {
        GIT_REPO = 'https://github.com/bharathsavadatti447/Docker-assignment_1.git'
        BRANCH = 'main'
        IMAGE_NAME_1 = 'bharathsavadatti/c-app'
        IMAGE_NAME_2 = 'bharathsavadatti/java-app'
        IMAGE_NAME_3 = 'bharathsavadatti/python-app'
    }

    stages {
        stage('Checkout code') {
            steps {
                git branch: "${BRANCH}",
                    url: "${GIT_REPO}",
                    credentialsId: 'a5e5c631-8e24-48ee-9844-ea7c8b7a658d'
            }
        }

        stage('Docker login') {
            steps {
                script {
                    withCredentials([usernamePassword(credentialsId: 'Jenkins-Dockerhub', usernameVariable: 'DOCKER_USER', passwordVariable: 'DOCKER_PASS')]) {
                        sh """
                            echo "$DOCKER_PASS" | sudo docker login -u "$DOCKER_USER" --password-stdin
                        """
                    }
                }
            }
        }

        stage('Build and Push Images in Parallel') {
            parallel {
                stage('C App Build & Push') {
                    steps {
                        script {
                            dir('c-app') {
                                sh """
                                    sudo docker build -t ${IMAGE_NAME_1}:latest .
                                    sudo docker push ${IMAGE_NAME_1}:latest
                                """
                            }
                        }
                    }
                }

                stage('Java App Build & Push') {
                    steps {
                        script {
                            dir('java-app') {
                                sh """
                                    sudo docker build -t ${IMAGE_NAME_2}:latest .
                                    sudo docker push ${IMAGE_NAME_2}:latest
                                """
                            }
                        }
                    }
                }

                stage('Python App Build & Push') {
                    steps {
                        script {
                            dir('python-app') {
                                sh """
                                    sudo docker build -t ${IMAGE_NAME_3}:latest .
                                    sudo docker push ${IMAGE_NAME_3}:latest
                                """
                            }
                        }
                    }
                }
            }
        }

        stage('Docker Logout') {
            steps {
                sh 'sudo docker logout'
            }
        }
    }
}
