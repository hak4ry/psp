package Práctica_Productor_Consumidor;

import java.util.Random;

    class Deposito {
        private int combustible = 0;
        private final int capacidadMaxima = 1000;
        // Método sincronizado para que solo un hilo productor o consumidor acceda al depósito
        public synchronized void llenar(int litros) {
            while (combustible == capacidadMaxima) {
                try {
                    wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            combustible += litros;
            System.out.println("Productor ha llenado " + litros + " litros. Combustible total en depósito: " + combustible);
            notifyAll(); // Notifica a los camiones que pueden cargar
        }
        // Método sincronizado para que un camión cargue combustible
        public synchronized void cargar(int camionId) {
            while (combustible == 0) {
                try {
                    wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            int carga = Math.min(combustible, 200);
            combustible -= carga;
            System.out.println("Camión " + camionId + " ha cargado " + carga + " litros. Combustible restante en depósito: " + combustible);
            notifyAll();
        }
    }

    class Productor extends Thread {
        private Deposito deposito;

        public Productor(Deposito deposito) {
            this.deposito = deposito;
        }
        @Override
        public void run() {
            Random rand = new Random();
            for (int i = 0; i < 15; i++) {
                int litros = rand.nextInt(1001);
                deposito.llenar(litros);
                try {
                    Thread.sleep(1000);  // Simula el tiempo entre cada llenado
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
    class Camion extends Thread {
        private int id;
        private Deposito deposito;

        public Camion(int id, Deposito deposito) {
            this.id = id;
            this.deposito = deposito;
        }

        @Override
        public void run() {
            for (int i = 0; i < 5; i++) {  // Cada camión realiza 5 cargas
                deposito.cargar(id);
                try {
                    Thread.sleep(1500);  // Simula el tiempo entre cada carga
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            System.out.println("Camión " + id + " ha terminado de cargar y parte hacia su destino.");
        }
    }
    public class MuelleCarga {
        public static void main(String[] args) {
            Deposito deposito = new Deposito();
            Productor productor = new Productor(deposito);

            // Creamos 5 camiones
            Camion[] camiones = new Camion[5];
            for (int i = 0; i < camiones.length; i++) {
                camiones[i] = new Camion(i + 1, deposito);
                camiones[i].start();  // Iniciamos cada camión
            }

            productor.start();  // Iniciamos el hilo productor
        }
    }


