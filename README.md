# Algorithms and Data Structures Project
This is the epository for 2nd year class "Algoritmos e Estruturas de Dados"  of MIEIC(FEUP).

### Description
The project consists of a C++ implementation of a
moving company software on which assembles all information about the company. It was divided in two parts:
(Note: Portuguese Only)

#### First Part: Base Project

Uma empresa de mudanças internacionais pretende implementar um sistema informático para a gestão dos seus
serviços. A empresa mantém uma carteira de clientes empresariais e particulares, para além de prestar serviço a
clientes ocasionais, sem registo. Os clientes registados, portanto, podem assumir dois tipos: empresa ou particular.
Para cada cliente deve ser possível manter o seu perfil, com informações do tipo nome, morada, NIF, e o histórico
dos serviços contratados.
Um serviço corresponde a embalamento na origem (endereço, incluindo país e cidade, indicado pelo cliente),
viagem entre origem e o destino (indicado pelo cliente) e entrega. O serviço tem um valor associado, que depende
do volume transportado e distância entre origem e destino - caso a distância entre a origem e o destino exceda os
2000 km, o serviço terá um acréscimo de 10% do valor de serviço. O embalamento, viagem e entrega também
têm diferentes datas de realização, hora de início e hora de fim.
Os clientes registados podem usufruir de um serviço de armazenamento dos bens entre a data de chegada dos bens
ao país de destino e entrega no endereço do cliente. Caso o armazenamento não exceda 5 dias o serviço não terá
custos adicionais. Após estes 5 dias, o serviço tem um custo diário a ser definido pela empresa.
Os pagamentos do serviço de mudanças podem ser realizados de formas diferentes, nomeadamente: por cartão
multibanco, por cartão de crédito, e transferência bancária. Os clientes empresariais registados podem ainda
efectuar o pagamento no final do mês (para todas as mudanças realizadas entre o primeiro e o último dia do mês
anterior). Pagamentos em multibanco e transferência bancária são permitidos a todos os clientes; pagamentos em
cartão de crédito são permitidos apenas a clientes empresariais registados, e tem um acréscimo de 5% do valor do
serviço, pela transação do cartão

#### Second part: Adding features to base project using STL's data structures:
###### * Binary Search Trees:
Para efeitos de auditoria, a empresa precisa guardar o histórico dos serviços de mudança realizados. As
faturas das mudanças executadas são então guardadas numa Árvore Binária de Pesquisa, ordenadas
alfabeticamente pelo nome do cliente; para clientes com histórico de muitas mudanças, estas são
ordenadas a partir das mais antigas, até às mais recentes.
###### * PrioriteQueue:
Para melhor gerir as solicitações de mudanças, e nomeadamente as viaturas utilizadas no transporte dos
bens, dado o aumento constante do número de clientes e a limitada capacidade da frota da empresa, o
sistema mantém numa Fila de Prioridade as viaturas a serem utilizadas nas próximas mudanças, e numa
fila normal os próximos pedidos. As viaturas são ordenadas pelo tempo expectável (valor a atribuir pelo
utilizador) em que estarão disponíveis depois de concluírem a viagem de transporte e regresso. As
viaturas que estiverem disponíveis mais cedo encontram-se no topo da fila de prioridade. Em algumas
situações, algumas viaturas poderão necessitar deixar o serviço mais cedo (manutenção, por ex),
podendo ser necessário saírem da fila dos próximos serviços.
###### * Hash Table:
Clientes que não utilizam os serviços da empresa por mais de um determinado tempo, são guardados
numa Tabela de Dispersão como clientes inativos. Sempre que voltarem a utilizar um serviço, passam
novamente a clientes ativos. As moradas são atualizadas, em campanhas promocionais, de tempos em
tempos, de forma a ter esta informação sempre válida no sistema, para os clientes inativos

### Built with
This project was built with Eclipse C++ Neon.


